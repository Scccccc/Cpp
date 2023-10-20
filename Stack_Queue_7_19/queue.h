#pragma once
#include <list>
#include <vector>
#include <deque>

namespace Mycode
{
	template<class T, class Con = deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			//vector没有pop_front接口
			_con.pop_front();
		}
		T& back()
		{
			return _con.back();
		}
		T& front()
		{
			return _con.front();
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

	void test_queue()
	{
		queue<int> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;

		/*queue<int, list<int>> ql;
		ql.push(1);
		ql.push(2);
		ql.push(3);
		ql.push(4);
		while (!ql.empty())
		{
			cout << ql.front() << " ";
			ql.pop();
		}
		cout << endl;*/



	}
}