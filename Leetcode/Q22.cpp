//给定n，输出n个括号可能的组成形式。
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<int>> record; //记录1～n，每个大小的数据。避免重复递归。空间换时间。
    }    
    vector<string> solve(vector<string> comb,int i,int n)
    {
        if(i > n) return comb;
        
    
        return solve(result,i+1,n);
    }
};