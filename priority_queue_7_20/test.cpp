#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>

using namespace std;

#include "PriorityQueue.h"
void test_priority_queue()
{
	priority_queue<int> pq;
	pq.push(1);
	pq.push(9);
	pq.push(6);
	pq.push(4);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	pq.push(10);
	cout << pq.top() << endl;
}


int main()
{
	Mycode::test_priority_queue();

	return 0; 
}