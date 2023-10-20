#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include "vector.h"

//返回数字键所有字母组合
//class Solution {
//
//    string strA[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
//public:
//    void Combin(string digits, int level, string ConbinStr, vector<string>& v)
//    {
//        if (level == digits.size())
//        {
//            v.push_back(ConbinStr);
//            return;
//        }
//        int num = digits[level] - '0';
//        string str = strA[num];
//        for (size_t i = 0; i < str.size(); ++i)
//        {
//            Combin(digits, level + 1, ConbinStr + str[i], v);
//        }
//
//    }
//    vector<string> letterCombinations(string digits) {
//
//        vector<string> v;
//        if (digits.empty())
//            return v;
//        Combin(digits, 0, "", v);
//        return v;
//    }
//};

int main()
{
	Mycode::test_vector1();
	return 0;
}