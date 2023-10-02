#pragma once


template<class K>
struct DefultHashfunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct DefultHashfunc<string>
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (auto ch : str)
		{
			hash *= 131;
			hash += ch;
		}
		return hash;
	}
};
namespace Open_address
{
	enum STATE
	{
		EXIST,
		EMPTY,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		STATE _state = EMPTY;

		//HashData(const pair<K, V>& kv)
		//	:_kv(kv)
		//	,_state(EMPTY)
		//{}
	};

	template<class K, class V, class HashFunc = DefultHashfunc<K>>
	class HashTable
	{
	public:
		HashTable()
			:_n(0)
		{
			_table.resize(10);
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}
			//扩容
			if ((double)_n / (double)_table.size() >= 0.7)
			{
				size_t newsize = _table.size() * 2;

				HashTable<K, V, HashFunc> newtable;
				newtable._table.resize(newsize);
				for (size_t i = 0; i < _table.size(); ++i)
				{
					if (_table[i]._state == EXIST)
					{
						newtable.Insert(_table[i]._kv);
					}
				}
				_table.swap(newtable._table);
			}
			HashFunc hf;
			size_t hashi = hf(kv.first) % _table.size();
			while (_table[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _table.size();
			}
			_table[hashi]._kv = kv;
			_table[hashi]._state = EXIST;
			++_n;
			return true;
		}
		HashData<const K, V>* Find(const K& key)
		{
			HashFunc hf;

			size_t hashi = hf(key) % _table.size();
			while (_table[hashi]._state != EMPTY)
			{
				if (_table[hashi]._kv.first == key && _table[hashi]._state == EXIST)
				{
					return (HashData<const K, V>*)&_table[hashi];
				}
				++hashi;
				hashi %= _table.size();
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<const K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
			return false;
		}
	private:
		vector<HashData<K, V>> _table;
		size_t _n; //有效数据个数 
	};
}

namespace hash_bucket
{
	template<class T>
	struct HashData
	{
		T _data;
		HashData<T>* _next;

		HashData(const T& data)
			:_data(data)
			,_next(nullptr)
		{}

	};
	template<class K, class T, class KeyofT, class HashFunc>
	class HashTable;

	template<class K, class T, class Ptr, class Ref, class KeyofT, class HashFunc>
	struct HashIterator
	{
		typedef HashData<T> Node;
		typedef HashIterator<K, T, Ptr, Ref, KeyofT, HashFunc> Self;

		typedef HashIterator<K, T, T*, T&, KeyofT, HashFunc> iterator;

		Node* _node;
		const HashTable<K, T, KeyofT, HashFunc>* _pht;

		HashIterator(Node* node, const HashTable<K, T, KeyofT, HashFunc>* pht)
			:_node(node)
			,_pht(pht)
		{}

		HashIterator(const iterator& it)
			:_node(it._node)
			,_pht(it._pht)
		{}


		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}

		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				KeyofT kot;
				HashFunc hf;
				size_t hashi = hf(kot(_node->_data)) % _pht->_table.size();

				++hashi;
				while (hashi < _pht->_table.size())
				{
					if (_pht->_table[hashi])
					{
						_node = _pht->_table[hashi];
						return *this;
					}
					else
					{
						++hashi;
					}
				}

				_node = nullptr;
			}
			return *this;
		}
	};
	template<class K, class T, class KeyofT, class HashFunc = DefultHashfunc<K>>
	class HashTable
	{
		typedef HashData<T> Node;
		
	public:
		typedef HashIterator<K, T, T*, T&, KeyofT, HashFunc> iterator;
		typedef HashIterator<K, T, const T*, const T&, KeyofT, HashFunc> const_iterator;

		//友元函数
		template<class K, class T, class Ptr, class Ref, class KeyofT, class HashFunc>
		friend struct HashIterator;
		iterator begin()
		{
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return iterator(cur, this);
				}
			}
			return iterator(nullptr, this);
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		const_iterator begin() const
		{
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return const_iterator(cur, this);
				}
			}
			return const_iterator(nullptr, this);
		}

		const_iterator end() const
		{
			return const_iterator(nullptr, this);
		}

		HashTable()
		{
			_table.resize(10, nullptr);
		}

		~HashTable()
		{
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
			}
		}

		pair<iterator, bool> Insert(const T& data)
		{
			KeyofT kot;
			auto it = Find(kot(data));
			if (it != end())
			{
				return make_pair(it, false);
			}
			HashFunc hf;
			//扩容
			if (_n == _table.size())//负载因子==1扩容  == _n / _table.size() == 1
			{
				size_t newsize = _table.size() * 2;
				vector<Node*> newtable;
				newtable.resize(newsize, nullptr);
				//遍历旧表
				for (size_t i = 0; i < _table.size(); ++i)
				{
					Node* cur = _table[i];
					while (cur)
					{
						Node* next = cur->_next;

						cur->_next = newtable[i];
						newtable[i] = cur;

						cur = next;
					}
				}
				_table.swap(newtable);
			}
			//头插
			size_t hashi = hf(kot(data)) % _table.size();
			Node* newnode = new Node(data);

			newnode->_next = _table[hashi];
			_table[hashi] = newnode;
			++_n;
			return make_pair(iterator(newnode, this), true);
		}

		iterator Find(const K& key)
		{
			KeyofT kot;
			HashFunc hf;
			size_t hashi = hf(key) % _table.size();
			Node* cur = _table[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur, this);
				}
				cur = cur->_next;

			}
			return end();
		}

		iterator Erase(const K& key)
		{
			KeyofT kot;
			HashFunc hf;
			size_t hashi = hf(key) % _table.size();
			Node* cur = _table[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_table[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					--_n;
					return iterator(prev, this);
				}
				prev = cur;
				cur = cur->_next;
			}
			return end();
		}

		void Print()
		{
			for (size_t i = 0; i < _table.size(); ++i)
			{
				printf("[%d]:", i);
				Node* cur = _table[i];
				while (cur)
				{
					cout << cur->_kv.first << ":" << cur->_kv.second << "->";
					cur = cur->_next;
				}
				cout << "NULL" << endl;
			}
			cout << endl;
		}

	private:
		vector<Node*> _table;
		size_t _n = 0;
	};
}