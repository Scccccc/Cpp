#pragma once

template<class K, class V>
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;

	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{

		if (_root == nullptr)
		{
			_root = new Node(kv);
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
			else if(cur->_kv.first > kv.first)
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
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		cur->_parent = parent;

		//控制平衡因子
		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//左单旋
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				//右单旋
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				//右左双旋
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				//左右双旋
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}

	bool Isbalance()
	{
		return IsbalanceTree(_root);
	}

private:
	//左单旋
	void RotateL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;
		
		parent->_right = curleft;
		
		if (curleft)
		{
			curleft->_parent = parent;
		}
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

		parent->_bf = cur->_bf = 0;
	}
	//右单旋
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

		parent->_bf = cur->_bf = 0;
	}
	//右左双旋
	void RotateRL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;

		int bf = curleft->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		//控制平衡因子
		if (bf == 0)
		{
			curleft->_bf = 0;
			cur->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 1)
		{
			curleft->_bf = 0;
			cur->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			curleft->_bf = 0;
			cur->_bf = 1;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	//左右双旋
	void RotateLR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curright = cur->_right;

		int bf = curright->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 0)
		{
			curright->_bf = 0;
			cur->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 1)
		{
			curright->_bf = 0;
			cur->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			curright->_bf = 0;
			cur->_bf = 0;
			parent->_bf = 1;
		}
		else
		{
			assert(false);
		}
	}

	int Treehigh(Node* root)
	{
		if (root == nullptr)
			return 0;

		int lefttree = Treehigh(root->_left);
		int righttree = Treehigh(root->_right);

		return lefttree > righttree ? lefttree + 1 : righttree + 1;
	}

	bool IsbalanceTree(Node* root)
	{
		if (root == nullptr)
			return true;

		int lefttree = Treehigh(root->_left);
		int righttree = Treehigh(root->_right);
		if (righttree - lefttree != root->_bf)
		{
			cout << "平衡因子异常：" << root->_kv.first << "->" << root->_bf << endl;
			return false;
		}


		return abs(lefttree - righttree) < 2 
			&& IsbalanceTree(root->_left) 
			&& IsbalanceTree(root->_right);

	}

private:
	Node* _root = nullptr;
	
};