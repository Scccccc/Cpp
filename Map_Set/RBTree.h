#pragma once

enum Colour
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	Colour _col;
	T _data;

	RBTreeNode(const T& data)
		:_data(data)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_col(RED)
	{}
};
template<class T, class Ptr, class Ref>
struct __TreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __TreeIterator<T, Ptr, Ref> Self;
	typedef __TreeIterator<T, T*, T&> iterator;


	Node* _node;
	__TreeIterator(Node* node)
		:_node(node)
	{}
	__TreeIterator(const iterator& it)
		:_node(it._node)
	{}
	Ref operator*() 
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& node) const
	{
		return _node != node._node;
	}
	bool operator==(const Self& node) const
	{
		return _node == node._node;
	}


	Self& operator--()
	{
		Node* NodeLeft = _node->_left;
		if (_node->_left)
		{
			while (NodeLeft->_right)
			{
				NodeLeft = NodeLeft->_right;
			}
			_node = NodeLeft;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;

			while (parent && cur == parent->_left)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	Self& operator--(int)
	{
		Self temp(*this);
		Node* NodeLeft = _node->_left;
		if (_node->_left)
		{
			while (NodeLeft->_right)
			{
				NodeLeft = NodeLeft->_right;
			}
			_node = NodeLeft;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;

			while (parent && cur == parent->_left)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return temp;
	}


	Self& operator++()
	{
		Node* NodeRight = _node->_right;
		if (_node->_right)
		{
			while (NodeRight->_left)
			{
				NodeRight = NodeRight->_left;
			}
			_node = NodeRight;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}

			_node = parent;
		}
		return *this;
	}
};

template<class K, class T, class KeyofT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __TreeIterator<T, T*, T&> iterator;
	typedef __TreeIterator<T, const T*, const T&> const_iterator;

	const_iterator begin() const
	{
		Node* mostleft = _root;
		while (mostleft && mostleft->_left)
		{
			mostleft = mostleft->_left;
		}
		return const_iterator(mostleft);
	}

	const_iterator end() const
	{
		return const_iterator(nullptr);
	}

	iterator begin()
	{
		Node* mostleft = _root;
		while (mostleft && mostleft->_left)
		{
			mostleft = mostleft->_left;
		}
		return iterator(mostleft);
	}

	iterator end()
	{
		return iterator(nullptr);
	}



	pair<iterator, bool> Insert(const T& data)
	{
		
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}
		KeyofT kot;
		
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}
		Node* newnode = cur;
		cur = new Node(data);
		cur->_col = RED;
		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		//控制颜色
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				//uncle存在且为红
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续向上调整
					cur = grandfather;
					parent = cur->_parent;
				}
				//uncle不存在 或者 uncle存在且为黑
				else
				{
					if (parent->_left == cur)
					{
						//    g
						//  p
						//c
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else if(parent->_right = cur)
					{
						//     g
						//  p
						//    c
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;

					}
					else
					{
						return make_pair(iterator(cur), false);
					}

				}
				
			}
			else //parent == grandfather->_right
			{
				Node* uncle = grandfather->_left;
				if(uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续向上调整
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (parent->_right == cur)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else if(parent->_left == cur)
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						return make_pair(iterator(cur), false);
					}

				}
				
			}

			_root->_col = BLACK;

		}

		return make_pair(iterator(newnode), true);
	}
	bool CheckColour(Node* root, int blacknumber, int benchmark)
	{
		if (root == nullptr)
		{
			if (blacknumber != benchmark)
			{
				return false;
			}
			return true;
		}

		if (root->_col == BLACK)
		{
			++blacknumber;
		}

		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << root->_kv.first << "出现颜色错误" << endl;
			return false;
		}

		return CheckColour(root->_left, blacknumber, benchmark)
			&& CheckColour(root->_right, blacknumber, benchmark);
	}

	bool Isbalance()
	{
		return Isbalance(_root);
	}


	bool Isbalance(Node* root)
	{
		if (root == nullptr)
			return true;

		if (root->_col != BLACK)
			return false;

		//基准值
		Node* cur = _root;
		int benchmark = 0;
		while (cur)
		{
			if (cur->_col == BLACK)
				++benchmark;

			cur = cur->_left;
		}


		return CheckColour(root, 0, benchmark);
	}

private:
	void RotateL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;

		parent->_right = curleft;

		if (curleft)
			curleft->_parent = parent;

		cur->_left = parent;

		Node* ppnode = parent->_parent;
		parent->_parent = cur;

		if (parent == _root)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else
			{
				ppnode->_right = cur;
			}
			cur->_parent = ppnode;
		}
	}

	void RotateR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curright = cur->_right;

		parent->_left = curright;

		if (curright)
			curright->_parent = parent;

		cur->_right = parent;

		Node* ppnode = parent->_parent;
		parent->_parent = cur;


		if (parent == _root)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else
			{
				ppnode->_right = cur;
			}
			cur->_parent = ppnode;
		}
	}

private:
	Node* _root = nullptr;
};