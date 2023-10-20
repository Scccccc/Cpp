#pragma once
#pragma once
#include <assert.h>
#include <vector>
#include "ReverseIterator.h"


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

		bool operator!=(const Self& it) const
		{
			return _node != it._node;
		}
		bool operator==(const Self& it) const
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
		//反向迭代器
		typedef ReverseIterator<iterator, T&, T*> reverse_iterator;
		typedef ReverseIterator<const iterator, const T&, const T*> const_reverse_iterator;

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rbegin() const
		{
			return reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			return reverse_iterator(begin());
		}

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

		list<int>::reverse_iterator rit = lt.rbegin();
		while (rit != lt.rend())
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;
	}

}