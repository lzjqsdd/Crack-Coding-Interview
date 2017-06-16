//0~9在手机的数字键盘，给定一个按键的序列，给出可能的字母的组合。
//递归回溯求解所有的组合。
//具体答案在leetcode网站上。

#include<map>
#include<vector>
#include<iostream>
using namespace std;


map<char,string> dict = 
{
    {'1',""},
    {'2',"abc"},
    {'3',"def"},
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"},
    {'0'," "}
};

vector<string> solve(vector<string> comb,int i,string &input,map<char,string>&dict)
{
    if(i == input.size()) return comb;

    string tmp = dict[input[i]];
    vector<string> result;
    for(string cs:comb) //在当前组合每个都追加下一个字符
    {
        for(char ts:tmp)
        {
            result.push_back(cs.append(1,ts));
        }
    }

    return solve(result,i+1,input,dict);
}


int main()
{
    string digits = "32";
    vector<string>comb = {""};
    vector<string> result = solve(comb,0,digits,dict);
    return 0;
}

//=====================================
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        map<char,string> dict = 
        {
            {'1',""},
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"},
            {'0',""}
        };
        vector<string>comb = {""};
        return solve(comb,0,digits,dict);
    }
    
    vector<string> solve(vector<string> comb,int i,string &input,map<char,string>&dict)
    {
        if(i == input.size()) return comb;
    
        string tmp = dict[input[i]];
        vector<string> result;
        for(string cs:comb) //在当前组合每个都追加下一个字符
        {

            for(char ts:tmp)
            {
                string ss = cs;
                result.push_back(ss.append(1,ts));
            }
        }
    
        return solve(result,i+1,input,dict);
    }
};



//第二遍
//手机键盘，打出一组数字(0~9),因为每个键盘上有多个字母，给出所有可能的字母组合
//思路：
//建立 数字和字母之间的映射map
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        map<char,string> dict = 
        {
            {'1',""},
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"},
            {'0',""}
        };
        vector<string> result = {""};
        return letter(digits,0,dict,result);
    }

    //参数分别表示：输入的数字序列，当前处理第i个字母，字典，结果
    vector<string> letter(string &digits,int i,map<char,string>&dict,vector<string>comb)
    {
        if(i == digits.size()) return comb;
        vector<string> result;
        for(string str:comb)
        {
            for(char c:dict[digits[i]])
                result.push_back(string(str+c));
        }
        return letter(digits,i+1,dict,result);
    }
};