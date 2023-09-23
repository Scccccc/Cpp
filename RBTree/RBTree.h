#pragma once

enum Colour
{
	RED,
	BLACK
};

template<class K, class V>
struct RBTreeNode
{
	pair<K, V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_col(RED)
	{}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first < kv.first)
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
						return false;
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
						return false;
					}

				}
				
			}

			_root->_col = BLACK;

		}

		return true;
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