//题意：给定字符串数组，把可以“通过变换位置”互相转换的字符串归为一组
//["eat", "tea", "tan", "ate", "nat", "bat"], 
//eat,tea,ate为一组, nat,tan为一组，bat为一组

//思路:HashTable,key为统一的元素,value为字符串集合。通过对每个元素进行排序找到原始序列。
//14.04
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> dict;
        for(auto s: strs)
        {
            string tmp  =s;
            sort(tmp.begin(),tmp.end());
            if(dict.find(tmp) == dict.end()) //如果没有
                dict[tmp] = vector<string>(1,s);
            else
                dict[tmp].push_back(s); //如果有则继续加入
        }
        vector<vector<string>> result;
        for(auto d:dict)
            result.push_back(d.second);
        return result;
    }
};