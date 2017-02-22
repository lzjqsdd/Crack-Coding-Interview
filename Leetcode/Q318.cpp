//给定一组字符串，找出两个字符串其长度之积最大，但是这两个字符串没有相同的字母。

//思路：
//位运算。把a~z映射到26位长度上。

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size()==0) return 0;
        //因为求最长，所以尽可能让这两个单词长度大，预先从大到小排序，然后查找。
        //sort(words.begin(),words.end(),[](const string a,const string b){return a.size() > b.size();});    
        //for(string s:words) 
        //    cout << s << endl;
        int max = 0;
        for(int i=0;i<words.size()-1;i++)
        {
            int ni = getBit(words[i]);
            //cout << "i  " << bitset<32>(ni) << endl;
            for(int j=i+1;j<words.size();j++)
            {
                int nj = getBit(words[j]);
                //cout << "j  " << bitset<32>(nj) << endl;
                if((ni&nj) == 0) //说明两个字符串没有相同字母.这里的与运算带括号，不然运算顺序低于==
                {
                    int tmp = words[i].size() * words[j].size();
                    if(tmp > max) max = tmp; //可能无重复字母的符合条件有多个，选择最长的
                }
            }
        }
        return max;
    }

    int getBit(const string &s)
    {
        int n=0;
        for(char c:s)
            n = n|(1<<(c-'a'));
        return n;
    }
};