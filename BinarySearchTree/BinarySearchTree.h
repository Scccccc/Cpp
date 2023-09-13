#pragma once

namespace key
{

	template<class K>
	struct BSTreeNode
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;

		BSTreeNode(const K& key)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}
	};

	template<class K>
	class BinarySearchTree
	{
		typedef BSTreeNode<K> Node;
	public:
		BinarySearchTree()
			:_root(nullptr)
		{}

		BinarySearchTree(const BinarySearchTree<K>& t)
		{
			_root = Copy(t._root);
		}

		BinarySearchTree<K>& operator=(BinarySearchTree<K> t)
		{
			swap(_root, t._root);
			return *this;
		}

		~BinarySearchTree()
		{
			Destory(_root);
		}

		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key);
			if (parent->_key > key)
			{
				parent->_left = cur;
			}
			else
			{
				parent->_right = cur;
			}

			return true;
		}

		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else
				{
					return true;
				}
			}
			return false;
		}

		bool Erase(const K& key)
		{
			if (_root == nullptr)
			{
				return false;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				//找到了
				else
				{
					//左为空
					if (cur->_left == nullptr)
					{
						if (_root == cur)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_right == cur)
							{
								parent->_right = cur->_right;
							}
							else
							{
								parent->_left = cur->_right;
							}
						}
					}
					//右为空
					else if (cur->_right == nullptr)
					{
						if (_root == cur)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_right == cur)
							{
								parent->_right = cur->_left;
							}
							else
							{
								parent->_left = cur->_left;
							}
						}
					}
					//两边都不为空
					else
					{
						Node* parent = cur;
						Node* leftMax = cur->_left;
						while (leftMax->_right)
						{
							parent = leftMax;
							leftMax = leftMax->_right;
						}

						swap(cur->_key, leftMax->_key);



						if (parent->_left == leftMax)
						{
							parent->_left = leftMax->_left;

						}
						else
						{
							parent->_right = leftMax->_right;

						}

						cur = leftMax;
					}
					delete cur;
					return true;
				}
			}
			return false;
		}

		void Inorder()
		{
			_Inorder(_root);
			cout << endl;
		}
		//递归版本
		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:
		Node* Copy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			Node* copyroot = new Node(root->_key);
			copyroot->_left = Copy(root->_left);
			copyroot->_right = Copy(root->_right);

			return copyroot;

		}
		void Destory(Node*& root)
		{
			if (root == nullptr)
				return;

			Destory(root->_left);
			Destory(root->_right);
			delete root;
			root = nullptr;

		}
		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			//找到了
			else
			{
				Node* del = root;

				//左为空
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				//右为空
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				//左右都为空
				else
				{
					Node* leftMax = root->_left;
					while (leftMax->_right)
					{
						leftMax = leftMax->_right;
					}
					swap(root->_key, leftMax->_key);

					return _EraseR(root->_left, key);

				}
				delete del;
				return true;
			}
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				//把要插入的值直接链接给root，root是root->left或者root->right的别名
				root = new Node(key);
				return true;
			}

			if (root->_key > key)
			{
				return _InsertR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _InsertR(root->_right, key);
			}
			else
			{
				return false;
			}
		}
		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else
			{
				return true;
			}
		}
		void _Inorder(Node* root)
		{
			if (root == nullptr)
				return;

			_Inorder(root->_left);
			cout << root->_key << " ";
			_Inorder(root->_right);
		}

	private:
		Node* _root;
	};

	void testBSTree()
	{
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		BinarySearchTree<int> bst;

		for (auto e : a)
		{
			bst.InsertR(e);
		}
		bst.Inorder();

		bst.EraseR(8);
		//bst.Inorder();

		bst.EraseR(3);
		//bst.Inorder();

		bst.EraseR(1);
		//bst.Inorder();

		bst.EraseR(13);
		bst.Inorder();

	}
	void testBSTree2()
	{
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		BinarySearchTree<int> bst;

		for (auto e : a)
		{
			bst.Insert(e);
		}
		bst.Inorder();

		//拷贝构造
		BinarySearchTree<int> bst2(bst);
		bst2.Inorder();

		BinarySearchTree<int> bst3;

		//赋值
		bst3 = bst2;
		bst3.Inorder();

	}
}

namespace key_value
{
	template<class K, class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;
		K _key;
		V _value;

		BSTreeNode(const K& key, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			,_value(value)
		{}
	};

	template<class K, class V>
	class BinarySearchTree
	{
		typedef BSTreeNode<K, V> Node;
	public:
		
		BinarySearchTree()
			:_root(nullptr)
		{}

		void Inorder()
		{
			_Inorder(_root);
			cout << endl;
		}
		//递归版本
		Node* FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key, const V& value)
		{
			return _InsertR(_root, key, value);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:
		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			//找到了
			else
			{
				Node* del = root;

				//左为空
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				//右为空
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				//左右都为空
				else
				{
					Node* leftMax = root->_left;
					while (leftMax->_right)
					{
						leftMax = leftMax->_right;
					}
					swap(root->_key, leftMax->_key);

					return _EraseR(root->_left, key);

				}
				delete del;
				return true;
			}
		}

		bool _InsertR(Node*& root, const K& key, const V& value)
		{
			if (root == nullptr)
			{
				//把要插入的值直接链接给root，root是root->left或者root->right的别名
				root = new Node(key, value);
				return true;
			}

			if (root->_key > key)
			{
				return _InsertR(root->_left, key, value);
			}
			else if (root->_key < key)
			{
				return _InsertR(root->_right, key, value);
			}
			else
			{
				return false;
			}
		}
		Node* _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
				return nullptr;

			if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else
			{
				return root;
			}
		}
		void _Inorder(Node* root)
		{
			if (root == nullptr)
				return;

			_Inorder(root->_left);
			cout << root->_key << root->_value << " ";
			_Inorder(root->_right);
		}

	private:
		Node* _root;
	};

	void testBSTree()
	{
		BinarySearchTree<string, string> dict;
		dict.InsertR("code", "代码");
		dict.InsertR("webside", "网页");
		dict.InsertR("computer", "电脑");
		dict.InsertR("phone", "手机");

		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>* ret = dict.FindR(str);
			if (ret)
			{
				cout << ret->_value << endl;
			}
			else
			{
				cout << "无此单词" << endl;
			}
		}
	}
	//计数树
	void testBSTree2()
	{
		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
						"苹果", "香蕉", "苹果", "香蕉" };

		BinarySearchTree<string, int> CountTree;

		for (auto& str : arr)
		{
			auto ret = CountTree.FindR(str);
			if (ret == nullptr)
			{
				CountTree.InsertR(str, 1);
			}
			else
			{
				ret->_value++;
			}
		}
		CountTree.Inorder();
	}
}