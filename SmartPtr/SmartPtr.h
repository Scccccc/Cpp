#pragma once

namespace Mycode
{
	//auto_ptr
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ps)
			:_ptr(ps._ptr)
		{
			ps._ptr = nullptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		~auto_ptr()
		{
			cout << "~auto_ptr()" << endl;
		}
	private:
		T* _ptr;
	};

	//unique_ptr
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		~unique_ptr()
		{
			cout << "~unique_ptr()" << endl;
		}
		//防拷贝
		unique_ptr(unique_ptr<T>& ps) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>& ps) = delete;

	private:
		T* _ptr;
	};

	//shared_ptr
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			,_pcount(new int(1))
		{}

		template<class D>
		shared_ptr(T* ptr, D del)
			:_ptr(ptr)
			, _pcount(new int(1))
			,_del(del)
		{}

		shared_ptr(shared_ptr<T>& ps)
			:_ptr(ps._ptr)
			,_pcount(ps._pcount)
		{
			++(*_pcount);
		}

		//p1 = p4
		shared_ptr<T>& operator=(shared_ptr<T>& ps)
		{
			if (_ptr == ps._ptr)
				return ps;

			if ((*_pcount) == 1)
			{
				delete _ptr;
				delete _pcount;
			}
			--(*_pcount);

			_ptr = ps._ptr;
			_pcount = ps._pcount;
			++(*_pcount);
			
			return *this;
		}

		~shared_ptr()
		{
			if (--(*_pcount) == 0)
			{
				_del(_ptr);
				delete _pcount;
				cout << "~shared_ptr()" << endl;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->() 
		{
			return _ptr;
		}

		T* get() const 
		{
			return _ptr;
		}

	private:
		T* _ptr;
		int* _pcount;
		function<void(T*)> _del = [](T* ptr) {delete ptr;};
	};

	//weak_ptr
	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}

		weak_ptr(shared_ptr<T>& ps)
			:_ptr(ps.get())
		{}

		weak_ptr<T>& operator=(shared_ptr<T>& ps)
		{
			_ptr = ps.get();
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};
}

