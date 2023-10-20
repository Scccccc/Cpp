#pragma once
#include "RBTree.h"

namespace Mycode
{
	template<class K>
	class set
	{
		struct SetKeyofT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, K, SetKeyofT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyofT>::const_iterator const_iterator;
		iterator begin() const
		{
			return _t.begin();
		}
		iterator end() const
		{
			return _t.end();
		}
		//iterator
		pair<iterator, bool> insert(const K& key)
		{
			//需要拿普通的迭代器构造一个const迭代器
			pair<typename RBTree<K, K, SetKeyofT>::iterator, bool> ret = _t.Insert(key);
			return pair<iterator, bool>(ret.first, ret.second);
		}
		
	private:
		RBTree<K, K, SetKeyofT> _t;
		
	};
	
}