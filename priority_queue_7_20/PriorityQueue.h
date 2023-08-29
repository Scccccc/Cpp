#pragma once
#include <vector>

template<class T>
struct Less
{
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};

namespace Mycode
{
	template<class T, class container = vector<T>, class compare = Less<T>>
	class priority_queue
	{
		void AdjustDown(int parent)
		{
			compare com;
			int child = (parent * 2 + 1);

			while (child < _con.size())
			{
				if (child+1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}

				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = (parent * 2 + 1);
				}
				else
				{
					break;
				}
			}
		}

		void AdjustUp(int child)
		{
			compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
	public:
		priority_queue()
		{}
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				++first;
			}

			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i)
			{
				AdjustDown(i);
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);

			AdjustUp(_con.size()-1);
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}
		bool empty()
		{
			return _con.empty();
		}

		const T& top()
		{
			return _con[0];
		}
	private:
		container _con;
	};

	void test_priority_queue()
	{
		priority_queue<int, vector<int>, Less<int>> pq;
		//priority_queue<int> pq;

		pq.push(1);
		pq.push(2);
		pq.push(45);
		pq.push(6);
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}