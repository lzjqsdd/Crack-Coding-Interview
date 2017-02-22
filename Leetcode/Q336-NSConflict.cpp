#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

class Solution{
    public:
    vector<vector<int>> palindromePairs(vector<string>&words){
        vector<vector<int>> result;
        map<string,int> dict;
        for(int i = 0;i<words.size();i++) dict[words[i]] = i;

        for(int i = 0;i<words.size();i++)
        {
            //构造能够组成回文串的目标string
            //分为奇数和偶数，做两次循环分别构造。

            //构造偶数的回文串。
            int len = words[i].size();
            for(int k=0;k<len;k++)
            {
                string target = words[i];
                if(k == 0)
                {
                    reverse(target.begin(),target.end());
                    if(dict.find(target)!=dict.end())
                    {
                        vector<int> tmp = {dict[target],i};
                        result.push_back(tmp);
                    } 
                }
                else if(k == len-1)
                {
                    reverse(target.begin(),target.end());
                    if(dict.find(target)!=dict.end())
                    {
                        vector<int> tmp = {i,dict[target]};
                        result.push_back(tmp);
                    } 
                }
                //在前面构造或者后面构造。
                else if(k+1 < len-k-1) //在前面构造
                {
                    int j1 = k-1;
                    int j2 = k;
                    while(j1>=0)
                    {
                        if(words[i][j1--] != words[i][j2++] ) break;
                    }
                    if(j1 < 0) //说明原串对称，target就是欠缺的部分。 
                    {
                        target.erase(0,k-1);
                        reverse(target.begin(),target.end());
                        if(dict.find(target)!=dict.end())
                        {
                        vector<int> tmp = {dict[target],i};
                        result.push_back(tmp);
                        } 
                    }
                }
                else if(k+1 > len-k-1)
                {
                    int j1 = k-1;
                    int j2 = k;
                    while(j2<=len-1)
                    {
                        if(words[i][j1--] != words[i][j2++] ) break;
                    }
                    if(j2 == len) //说明原串对称，target就是欠缺的部分。 
                    {
                        target.erase(0,k-1);
                        reverse(target.begin(),target.end());
                        if(dict.find(target)!=dict.end())
                        {
                        vector<int> tmp = {i,dict[target]};
                        result.push_back(tmp);
                        } 
                    }
                }
                
            }
        }
    }
}

Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]


abcd