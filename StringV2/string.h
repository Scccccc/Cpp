#pragma once
#include <assert.h>

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
			memcpy(_str, str,_size+1);
		}

		//拷贝构造
		string(const string& s)
		{
			_str = new char[s._capacity + 1];
			memcpy(_str, s._str, s._size+1);
			_size = s._size;
			_capacity = s._capacity;

		}
		//v1
		//string& operator=(const string& str)
		//{
		//	if (this != &str)
		//	{
		//		char* tmp = new char[str._capacity + 1];
		//		memcpy(tmp, str._str, str._size+1);
		//		delete[] _str;
		//		_str = tmp;
		//		_size = str._size;
		//		_capacity = str._capacity;
		//	}
		//	return *this;
		//	
		//}
		
		
		void swap(string& str)
		{
			std::swap(_str, str._str);
			std::swap(_size, str._size);
			std::swap(_capacity, str._capacity);
		}

		//v2
	/*	string& operator=(const string& str)
		{
			if (this != &str)
			{
				string tmp(str);
				swap(tmp);
			}
			return *this;
		}*/

		//v3
		string& operator=(string str)
		{
			swap(str);
			return *this;
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
			assert(pos <= _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos <= _size);

			return _str[pos];
		}

		void reserve(size_t n = 0)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n+1];
				memcpy(tmp, _str, _size+1);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		//尾插
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_str[++_size] = '\0';
		}
		//追加
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			memcpy(_str + _size, str, len+1);
			_size += len;
		}

		//+=
		string& operator+= (char c)
		{
			push_back(c);
			return *this;
		}

		string& operator+= (const char* str)
		{
			append(str);
			return *this;
		}

		void insert(size_t pos, size_t n, char c)
		{
			assert(pos <= _size);
			if (_size + n > _capacity)
			{
				reserve(_size + n);
			}
			

			size_t end = _size;
			while (end >= pos && end != npos)
			{
				_str[end + n] = _str[end--];
			}

			for (size_t i = 0; i < n; i++)
			{
				_str[pos + i] = c;
			}
			_size += n;

		}


		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size+len);
			}

			//挪动数据
		/*	size_t end = _size;
			while ((int)end >= (int)pos)
			{
				_str[end + len] = _str[end--];
			}
			for (size_t i = 0; i < len; i++)
			{
				_str[pos+i] = str[i];
			}
			_size += len;*/

			size_t end = _size;
			while (end >= pos && end != npos)
			{
				_str[end + len] = _str[end--];
			}
			for (size_t i = 0; i < len; i++)
			{
				_str[pos + i] = str[i];
			}
			_size += len;
		}
		//指定删除
		void erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos <= _size);
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
				_str[_size] = '\0';
			}
			else
			{
				size_t end = pos + len;
				while(end <= _size)
				{
					_str[pos++] = _str[end++];
				}
				_size -= len;
			}
			
		}
		//查找一个字符
		size_t find(char c, size_t pos = 0) const
		{
			assert(pos < _size);
			for (size_t i = pos; i <= _size; i++)
			{
				if (_str[i] == c)
				{
					return i;
				}
			}
			return npos;
		}
		//查找字符串
		size_t find(const char* str, size_t pos = 0) const
		{
			assert(pos < _size);
			char* ptr = strstr(_str + pos, str);
			if (ptr)
			{
				return ptr - _str;
			}
			else
			{
				return npos;
			}
		}

		string substr(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);
			size_t n = len;
			if (len == npos || len + pos > _size)
			{
				n = _size - pos;
			}

			string tmp;
			tmp.reserve(n);
			for (size_t i = pos; i < pos + n; i++)
			{
				tmp += _str[i];
			}
			return tmp;

		}
		//n长度
		void resize(size_t n, char c = '\0')
		{
			if (n < _size)
			{
				_str[n] = '\0';
			}
			else
			{
				reserve(n);
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = c;
				}
			}
			_size = n;
			_str[_size] = '\0';
		}

		//重载运算符比较大小
		bool operator<(const string& str) const
		{

			//v2
			int ret = memcmp(_str, str._str, _size < str._size ? _size : str._size);

			return ret == 0 ? _size < str._size : ret < 0;


			//v1版本
	/*		int i1 = 0;
			int i2 = 0;
			while (i1 < _size && i2 < str._size)
			{
				if (_str[i1] < str[i2])
				{
					return true;
				}
				else if (_str[i1] > str[i2])
				{
					return false;
				}
				else
				{
					i1++;
					i2++;
				}
			}
			if (i1 == _size && i2 != str._size)
			{
				return true;
			}
			else
			{
				return false;
			}*/

		}

		bool operator==(const string& str)const
		{
			return _size == str._size && memcmp(_str, str._str, _size) == 0;
		}

		bool operator<=(const string& str)const
		{
			return *this < str || *this == str;
		}

		bool operator>(const string& str)const
		{
			return !(*this <= str);
		}

		bool operator>=(const string& str)const
		{
			return *this > str || *this == str;
		}

		bool operator!=(const string& str)const
		{
			return !(*this == str);
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

			

	private:
		size_t _size;
		size_t _capacity;
		char* _str;
		const static size_t npos;
	};
	const size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& str)
	{
	/*	for (size_t i = 0; i < str.size(); i++)
		{
			out << str[i];
		}*/

		for (auto ch : str)
		{
			out << ch;
		}
		return out;
	}

	istream& operator>>(istream& in, string& str)
	{
		str.clear();
		char ch = in.get();

		//处理缓冲区前无效数据' ' && '\n'
		while (ch == ' ' || ch == '\n')
		{
			ch = in.get();
		}

		char buff[128];
		int i = 0;
		//in >> ch;
		while (ch != ' ' && ch != '\n')
		{

			buff[i++] = ch;
			if (i == 127)
			{
				buff[i] = '\0';
				str += buff;
				i = 0;
			}
			//in >> ch;
			ch = in.get();
		}
		if (i != 0)
		{
			buff[i] = '\0';
			str += buff;
		}

		return in;


		//v1
		//str.clear();
		//char ch = in.get();
		////in >> ch;
		//while (ch != ' ' && ch != '\n')
		//{
		//	str += ch;
		//	//in >> ch;
		//	ch = in.get();
		//}
		//return in;
	}

}