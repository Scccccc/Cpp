#pragma once

namespace Mycode
{
	class string
	{
	public:
		//迭代器
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}
		iterator End()
		{
			return _str + _size;
		}
		
		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}
		//构造函数
		string(const char* str = "")
		:_size(strlen(str))
		,_capacity(_size)
		,_str(new char[_capacity+1])
		{
			strcpy(_str, str);
		}
		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		//C接口
		const char* c_str()
		{
			return _str;
		}
		
		const size_t size() const
		{
			return _size;
		}

		char& operator[](size_t pos)
		{
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			return _str[pos];
		}

		void reserve(size_t n = 0)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n+1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_str[++_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str+ _size, str);
			_size += len;
		}
			



	private:
		size_t _size;
		size_t _capacity;
		char* _str;
	};
}