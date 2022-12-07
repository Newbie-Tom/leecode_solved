#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
private:
    /*
     *段位以0为开头的数字不合法
     *段位里有非正整数字符不合法
     *段位如果大于255了不合法
     */
    bool isIPValid(string s, int start, int end)
    {
        if (start > end)
            return false;
        if (s[start] == '0' && start != end) // 0开头的数字不合法
            return false;
        int num = 0;
        for (int i = start; i <= end; i++)
        {
            if (s[i] > '9' && s[i] < '0')
                return false;
            num = num * 10 + s[i] - '0';
            if (num > 255)
                return false;
        }
        return true;
    }

public:
    vector<string> res;
    void backtracking(string s, int startIndex, int pointNum)
    {
        //终止条件
        if (pointNum == 3)
        {
            if (isIPValid(s, startIndex, s.size() - 1))
            {
                res.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isIPValid(s, startIndex, i))
            {
                s.insert(s.begin() + i + 1, '.'); // i后面插入一个逗点
                pointNum++;
                backtracking(s, i + 2, pointNum); //插入逗点后下一个子串的起始位置为i+2
                pointNum--;                       //回溯
                s.erase(s.begin() + i + 1);       //回溯删掉逗点
            }
            else
                break;
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        res.clear();
        //剪枝
        if (s.size() < 4 || s.size() > 12)
            return res;
        backtracking(s, 0, 0);
        return res;
    }
};
