#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

//本题错在了substr的参数，第一个是npos ,第二个是nlen

class Solution{
    public:
    vector<vector<int> > palindromePairs(vector<string>&words){

        map<string,int> dict;
        vector<vector<int>> result;
        for(int i=0;i<words.size();i++) dict[words[i]] = i;

        //构造一个以滑动窗口，不断从原始串划过，看重叠部分是不是回文串，如果是在构造缺少的部分。
        for(int i=0;i<words.size();i++)
        {
            int len = words[i].size();
            //正向查看
            //先排除两个特殊的情况，最前面补和最后面补
            string target = words[i];
            reverse(target.begin(),target.end());
            if(dict.find(target) != dict.end())
            {
                if(dict[target] != i) //如果本身是回文，目标串还是本身。
                {
                    result.push_back({i,dict[target]});
                }
            }


            //本身是回文串，补空串
            if(isPalindrome(words[i]))
            {
                target = "";
                if(dict.find(target) != dict.end())
                {
                    if(dict[target] != i)
                    {
                        result.push_back({dict[target],i});
                        result.push_back({i,dict[target]});
                    }
                }
            } 


            
            string ws = words[i];
            reverse(ws.begin(),ws.end()); //提前反转，避免多次取子串再反转。
            
            for(int k=1;k<=len-1;++k)
            {
                
                //cout << words[i].substr(0,k) << "," << ws.substr(0,len-k) << endl;
                
                //cout << words[i].substr(len-k,k) << "," << ws.substr(k,len-k) << endl;
                
                if(isPalindrome(words[i].substr(0,k)))
                {
                    target = ws.substr(0,len-k);
                    if(dict.find(target) != dict.end())
                    {
                        if(dict[target] != i) //如果本身是回文，目标串还是本身。
                        {
                            result.push_back({dict[target],i});
                        }
                    }
                }
                
                if(isPalindrome(words[i].substr(len-k,k)))
                {
                    target = ws.substr(k,len-k);
                    
                    if(dict.find(target) != dict.end())
                    {
                        if(dict[target] != i) //如果本身是回文，目标串还是本身。
                        {
                            result.push_back({i,dict[target]});
                        }
                    }
                }
            }

        }


        return result;
    }

    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.size()-1;
        while(i<j)
        {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }      
};


[[3,0],[0,3],[3,2],[2,3],[0,2]]

["a","abc","aba",""]
[[0,3],[3,0],[2,3],[3,2]]