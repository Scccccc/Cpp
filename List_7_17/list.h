#pragma once
#pragma once
#include <assert.h>
namespace Mycode
{
	template<class T>
	struct list_node
	{
		list_node<T>* _prev;
		list_node<T>* _next;
		T _val;

		list_node(const T& val = T())
			:_prev(nullptr)
			, _next(nullptr)
			, _val(val)
		{}
	};
	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef list_node<T> Node;
		typedef _list_iterator<T, Ref, Ptr> Self;

		Node* _node;

		_list_iterator(Node* node)
			:_node(node)
		{}

		Ref operator* () 
		{
			return _node->_val;
		}
		Ptr operator->()
		{
			return &_node->_val;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}
		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}
		const_iterator begin() const
		{
			return _head->_next;
		}
		const_iterator end() const
		{
			return _head;
		}
		void Empty_init()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
		}
		list()
		{
			Empty_init();
		}
		list(const list<T>& lt)
		{
			Empty_init();

			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		void swap(list<T> lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);

		}

		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
			_size = 0;
		}
		void push_back(const T& val)
		{
			/*Node* tail = _head->_prev;
			Node* newnode = new Node(val);

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/

			insert(end(), val);
		}
		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}

		

		iterator insert(iterator pos, const T& val)
		{
			Node* newnode = new Node(val);
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			cur->_prev = newnode;
			newnode->_next = cur;
			newnode->_prev = prev;
			prev->_next = newnode;
			++_size;
			return newnode;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete cur;
			--_size;
			return next;
			
		}
		size_t size()
		{
			return _size;
		}
	private:
		Node* _head;
		size_t _size;
	};

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		lt.insert(lt.begin(), 100);
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	struct A
	{
		A(int a = 0, int b = 0)
			:_a(a)
			,_b(b)
		{}
		int _a;
		int _b;
	};

	void test_list2()
	{
		list<A> lt;
		lt.push_back(A(1, 1));
		lt.push_back(A(2, 2));
		lt.push_back(A(3, 3));
		lt.push_back(A(4, 4));
		list<A>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << (*it)._a << " " << (*it)._b << endl;
			cout << it->_a << " " << it->_b << endl;
			++it;
		}
		//cout << endl;
		list<int> lt1;
		lt1.push_front(1);
		lt1.push_front(2);
		lt1.push_front(3);
		lt1.push_back(4);
		lt1.push_back(5);
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		lt1.pop_back();
		lt1.pop_front();
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

	}
	void test_list3()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(1);
		lt1.push_back(1);
		lt1.push_back(1);
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		lt1.clear();
		lt1.push_back(2);
		lt1.push_back(12);
		lt1.push_back(12);
		lt1.push_back(12);
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		int n = lt1.size();
		cout << n << endl;
	}
	void test_list4()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		list<int> lt1(lt);
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt2;
		lt2 = lt1;
		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;
	}

}