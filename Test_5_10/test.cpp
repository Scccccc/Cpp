#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Solution
{
public:
	Solution()
	{
		cout << "Solution()" << endl;
	}

	int Sum_solution(int n = 0)
	{
		cout << "Sum_solution" << endl;

		return n;
	}

	~Solution()
	{
		cout << "~Solution()" << endl;
	}
};

int main()
{
	Solution().Sum_solution(10);

	Solution ls;
	ls.Sum_solution(1);


	const Solution& ra = Solution();

	return 0;
}


//int main()
//{
//	char arr[] = "abcdef";
//
//	printf("%c\n",*arr);
//	return 0;
//}