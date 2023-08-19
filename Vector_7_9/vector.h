#pragma once
#include <assert.h>
 
namespace Mycode
{
	template<typename T>
	class vector
	{
		typedef T* iterator;
		typedef const T* const_iterator;

	public:
		vector()
		:_start(nullptr)
		,_finish(nullptr)
		,_end_of_storage(nullptr)
		{}

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}



		void reverse(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				size_t sz = size();
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * sz);
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				size_t newcpacity = capacity() == 0 ? 4 : capacity() * 2;
				reverse(newcpacity);
			}
			*_finish = x;
			++_finish;
		}

		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _end_of_storage - _start;
		}


	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	void test_vector1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

	}
}