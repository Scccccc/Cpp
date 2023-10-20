#pragma once

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
	template<class T>
	struct _list_iterator
	{
		typedef list_node<T> Node;
		Node* _node;
		
		_list_iterator(Node* node)
			:_node(node)
		{}

		T& operator* ()
		{
			return _node->_val;
		}

		_list_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		_list_iterator<T> operator++(int)
		{
			_list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		bool operator!=(const _list_iterator<T>& it)
		{
			return _node != it._node;
		}
		bool operator==(const _list_iterator<T>& it)
		{
			return _node == it._node;
		}


	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef _list_iterator<T> iterator;
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}
		list()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
		}
		void push_back(const T& val)
		{
			Node* tail = _head->_prev;
			Node* newnode = new Node(val);

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
	private:
		Node* _head;
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
	}
}