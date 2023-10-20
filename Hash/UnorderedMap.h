#pragma once

#include "HashTable.h"

namespace Mycode
{
	template<class K, class V>
	class unordered_map
	{
		struct MapKeyofT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyofT>::iterator iterator;
		typedef typename hash_bucket::HashTable<K, pair<const K, const V>, MapKeyofT>::const_iterator const_iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		const_iterator begin() const 
		{
			return _ht.begin();
		}

		const_iterator end() const
		{
			return _ht.end();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		iterator Erase(const K& key)
		{
			return _ht.Erase(key);
		}

	private:
		hash_bucket::HashTable<K, pair<const K, V>, MapKeyofT> _ht;
	};
}