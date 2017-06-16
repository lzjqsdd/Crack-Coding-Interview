//Greedy

/*
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]


[5,0],[7,0],[5,2],[6,1],[4,4],[7,1],
*/


//首先考虑解的结构，确定最小的元素的位置之后，比如[4,4],因为其余元素都比4大，所以[4,4]的位置固定下来，其他元素不管怎么变
//都不会影响其位置。

//所以每次选择最小的元素确定位置，剩下的元素成为子问题继续处理。
//首先按照高度H排序(然后按照人数排序)
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
       //sort(people.begin(),people.end(),cmp);
       sort(people.begin(),people.end());
       vector<pair<int,int>> result(people.size(),pair<int,int>(-1,-1));
       for(auto p:people)
       {
           //cout << p.first << "," << p.second << endl;
           int i=0,k = -1;
           while(i<result.size() && k!=p.second)
           {
               if(result[i].first == -1 || result[i].first==p.first) k++; //这里的或条件比如[5,0],[5,5]其实和5相等的也算比它高的。
               i++;
           }
           cout << k << endl;
           result[i-1].first = p.first;
           result[i-1].second = p.second;
       }
       return result;
    }
private:
    static bool cmp(const pair<int,int>& p1,const pair<int,int>&p2){
        return p1.first < p2.first ? true : p1.second < p2.second;
    }
};

int main()
{
    vector<pair<int,int>> test;
    test.push_back(make_pair(7,0));
    test.push_back(make_pair(4,4));
    test.push_back(make_pair(7,1));
    test.push_back(make_pair(5,0));
    test.push_back(make_pair(6,1));
    test.push_back(make_pair(5,2));

    Solution s;
    s.reconstructQueue(test);

}


//first从大到小排序，sceond从小到大排序，因为大的相对顺序确定后，对于小的不论位置在哪里都不会影响
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto cmp = [](const pair<int,int>&p1,const pair<int,int>&p2)
        {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        };
        sort(people.begin(),people.end(),cmp);
        for(auto p:people) cout << p.first << "," << p.second << endl;
        vector<pair<int,int>> result;
        for(auto p:people) result.insert(result.begin()+p.second,p);
        return result;
    }
};