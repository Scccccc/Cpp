#pragma once

namespace Mycode
{
	template<class iterator, class Ref, class Ptr>
	struct ReverseIterator
	{
		typedef ReverseIterator<iterator, Ref, Ptr> Self;
		iterator _it;
		ReverseIterator(iterator it)
			:_it(it)
		{}
		Ref operator*()
		{
			iterator tmp = _it;
			return *(--tmp);
		}

		Ptr operator->()
		{
			return &(operator*());
		}
		Self& operator++()
		{
			--_it;
			return *this;
		}
		Self& operator--()
		{
			++_it;
			return *this;
		}
		bool operator!=(const Self& p)
		{
			return _it != p._it;
		}
	};
}