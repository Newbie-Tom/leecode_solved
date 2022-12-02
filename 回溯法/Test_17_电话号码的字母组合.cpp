#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
    vector<string> result;
    string s;
    void backtracking(const string& digits,int index)
    {
        //终止条件
        if(index==digits.size())    //index用于遍历叶子节点
        {
            result.push_back(s);
            return;
        }
        int digit = digits[index]-'0';  //将index指向的数字转为int
        string letters = letterMap[digit];
        for(int i=0;i<letters.size();i++)
        {
            s.push_back(letters[i]);
            backtracking(digits,index+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        s.clear();
        result.clear();
        if(digits.size()==0)
        {
            return result;
        }
        backtracking(digits,0);
        return result;
    }
};