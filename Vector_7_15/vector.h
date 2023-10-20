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
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			_start = new T[v.capacity()];
			//memcpy浅拷贝，掉用析构的时候指向的数据被销毁了
			//memcpy(_start, v._start, sizeof(T)*v.size());
			for (size_t i = 0; i < v.size(); i++)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.size();
			_end_of_storage =_start + v.capacity();
		}

		vector(size_t n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			resize(n, val);
		}
		//vector<int> v(10, 1)传过来是int类型，如果没有int的拷贝构造，它不会走size_t的拷贝构造，会走到迭代器区间的拷贝构造里
		vector(int n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			resize(n, val);
		}
		template<typename IputIterator>
		vector(IputIterator first, IputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
	/*	vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(v.capacity());
			for (auto e : v)
			{
				push_back(e);
			}
		}*/

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

		iterator begin() const
		{
			return _start;
		}
		iterator end() const
		{
			return _finish;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//cout << "reserve()->" << n << endl;
				T* tmp = new T[n];
				size_t sz = size();
				if (_start)
				{
					//memcpy浅拷贝，掉用析构的时候指向的数据被销毁了
					//memcpy(tmp, _start, sizeof(T) * sz);
					for (size_t i = 0; i < size(); i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}
		void resize(size_t n, T value = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = value;
					_finish++;
				}
				_finish = _start + n;
				_end_of_storage = _start + n;
			}
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const 
		{
			assert(pos < size());
			return _start[pos];
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}


		void push_back(const T& x)
		{
			/*	if (_finish == _end_of_storage)
				{
					size_t newcpacity = capacity() == 0 ? 4 : capacity() * 2;
					reserve(newcpacity);
				}
				*_finish = x;
				++_finish;*/

			insert(end(), x);
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos <= _finish && pos >= _start);

			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				size_t newcpacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcpacity);
				//内部迭代器失效问题
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *(end);
				--end;
			}

			*pos = x;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator it = pos+1;
			while (it != _finish)
			{
				*(it-1) = *it;
				++it;
			}
			--_finish;
			return pos;
		}

		void pop_back()
		{
			erase(end()-1);
		}

		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _end_of_storage - _start;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}


	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	void print(vector<int>& v)
	{
		for (auto e : v)
		{
			cout << e << " ";
		}
	}

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

	void test_vector2()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(5);
		v1.push_back(5);
		v1.push_back(5);
		v1.push_back(5);
		v1.push_back(5);


		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;


		v1.insert(v1.begin(), 100);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(5);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		for (size_t i = 0; i < v1.size(); ++i)
		{
			v1[i]++;
		}
		print(v1);
	}

	void test_vector4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(5);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		v1.erase(v1.end()-1);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		auto it = v1.begin();
		while (it != v1.end())
		{
			if (*it % 2 == 0)
			{
				v1.erase(it);
			}
			else
			{
				++it;
			}
		}
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		v1.pop_back();
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector5()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(5);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		v1.resize(11);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector6()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		vector<int> v1(v);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v2;
		v2.resize(10, 1);
		v1 = v2;
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

	}

	void test_vector7()
	{
		vector<string> v;
		v.push_back("1111111111111");
		v.push_back("2222222222222");
		v.push_back("3333333333333");
		v.push_back("4444444444444");
		v.push_back("5555555555555");
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		vector<string> v1(v);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;


	}
	void test_vector8()
	{
		vector<int> v(10, 1);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v1(v.begin(), v.end());
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;



		
	}
}