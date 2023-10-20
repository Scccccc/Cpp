#pragma once

#include "HashTable.h"

namespace Mycode
{
	template<class K>
	class unordered_set
	{
		struct SetKeyofT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, K, SetKeyofT>::const_iterator iterator;
		typedef typename hash_bucket::HashTable<K, K, SetKeyofT>::const_iterator const_iterator;

		iterator begin() const
		{
			return _ht.begin();
		}

		iterator end() const
		{
			return _ht.end();
		}

		pair<iterator, bool> insert(const K& key)
		{
			pair<hash_bucket::HashTable<K, K, SetKeyofT>::iterator, bool> ret = _ht.Insert(key);
			return pair<iterator, bool>(ret.first, ret.second);
		}

		iterator Erase(const K& key)
		{
			typename hash_bucket::HashTable<K, K, SetKeyofT>::iterator ret = _ht.Erase(key);
			return ret;
		}

	private:
		hash_bucket::HashTable<K, K, SetKeyofT> _ht;
	};
}