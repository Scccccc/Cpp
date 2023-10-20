#pragma once
#include <list>
#include <vector>
#include <deque>

namespace Mycode
{
	template<class T, class Con = deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		T& top()
		{
			return _con.back();
		}
		bool empty()
		{
			return _con.empty();
		}
		size_t size()
		{
			return _con.size();
		}

	private:
		Con _con;
	};

	void test_stack()
	{
		stack<int, vector<int>> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;

		stack<int, list<int>> lt;
		lt.push(1);
		lt.push(2);
		lt.push(3);
		lt.push(4);
		while (!lt.empty())
		{
			cout << lt.top() << " ";
			lt.pop();
		}
		cout << endl;

		

	}
}