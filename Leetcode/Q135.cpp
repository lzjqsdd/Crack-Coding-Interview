//分Candy问题
//题意：给定数组A,n个元素分别代表每个小孩的rating,给n给小孩分糖果需要满足一下条件：
//(1) 每个小孩至少一个糖果
//(2) rating高的小孩分的糖果应该比相邻的要大
//求最少分多少糖果可以满足条件。

//联想波峰图。（作为思路启发）

//Greedy 每次遇到小的直接给1个糖。。如果该小的并不是当前的谷底，肯定有更小的需要一个糖，那么需要
//更新前面的人的candy数以满足条件。

//14:07
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//只有比相邻高的才需要满足条件，如果出现相同，不需要分的candy也一样
//如果出现持续下降的序列，复杂度为O(n^2),则会TLE,
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() == 0) return 0;
        vector<int> result;
        result.push_back(1); //先给第一个人1个candy
        for(int i=1;i<ratings.size();++i)
        {
            //if(ratings[i] == ratings[i-1]) result.push_back(result.back());
            if(ratings[i] > ratings[i-1]) result.push_back(result.back()+1);
            else //ratings[i-1] > ratings[i]
            {
                result.push_back(1);
                int k = i;
                while(k >= 0)
                {
                    //这里可以改进，不用没次违背就修改。可以先保证左侧满足，然后自右向左调整来满足右侧元素
                    //或者检测到最低点时来调整
                    if(ratings[k] < ratings[k-1] && result[k] >= result[k-1]){ result[k-1] = result[k]+1;k--;}
                    //else if(ratings[k] == ratings[k-1] && result[k]!=result[k-1]) {result[k-1] = result[k];k--;}
                    else break;
                }
            }
        }
        return accumulate(result.begin(),result.end(),0);
        //for(auto x:result) cout<< x<< ",";
        //cout << endl;
    }
};



class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() == 0) return 0;
        vector<int> result;
        result.push_back(1); //先给第一个人1个candy
        for(int i=1;i<ratings.size();++i)
        {
            if(ratings[i] > ratings[i-1])
            {
                int k = i-1; //i-1为谷底
                while(k >= 0)
                {
                    if(ratings[k] < ratings[k-1] && result[k] >= result[k-1]){ result[k-1] = result[k]+1;k--;}
                    else break;
                }

                result.push_back(result.back()+1);
            }
            else //ratings[i-1] > ratings[i]
            {
                result.push_back(1);
            }
        }
        return accumulate(result.begin(),result.end(),0);
        //for(auto x:result) cout<< x<< ",";
        //cout << endl;
    }
};



/*
//寻找波峰波谷
//连续相同ratings之间没有可比性
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() == 0) return 0;
        int i = 0;
        int sum = 0;
        while(i < ratings.size())
        {
            if(ratings[i] < ratings[i+1])
            {
                int k_up = 0;
                while(i+1 < ratings.size() && ratings[i] <ratings[i+1]) {k_up++;i++;}
                sum += ((k_up+1)*k_up)/2;
            }
            else
            {
                int k_down = 0;
                while(i+1 < ratings.size() && ratings[i] > ratings[i+1]) {k_down++;i++;}
                k_down++;
                sum += ((k_down+1)*k_down)/2;
            }
        }
        return sum;
    }
};
*/

int main()
{
    vector<int> test = {3,4,5,5,4,3,3,2,6,5};
    //vector<int> test = {1,2,2,2,2,2};
    Solution s;
    cout << s.candy(test) << endl;
    return 0;
}


[0]
[3,4,5,5,4,3,3,2,6,5]
[1,2,2,2,2,2]
[2,3,1,4,2,3,4,4,4,3,2,1,6,7,8,2,2,3,5,1,5,67,7]
[1,1,1,1,1,1,1]
[1,2,1,2,1,2,1,2]
[10,9,8,7,6,5,4,3,2,1,0]




    class Solution {
    public:
        int candy(vector<int>& ratings) {
            const int len = ratings.size();
            if(len<=1) return len;
            
            int i, pPos, res=1, peak=1; // peak: # candies given to the i-1 child
            bool neg_peak = false; // flag to indicate if it is a local dip
            for(i=1; i<len;i++)
            {
                if(ratings[i] >= ratings[i-1]) 
                {   // it is increasing
                    if(neg_peak) 
                    {  // it is a local dip, we need to make sure i-1 has one candy
                        res -= (peak-1) * (i-pPos - (peak>0));
                        peak = 1;
                        neg_peak = false;
                    }
                   // update child i candy number, if equal, set to 1
                    peak = (ratings[i] == ratings[i-1])? 1:++peak;
                    res += peak;
                }
                else
                { // decreasing, just give one less candy, if it is the starting point of a decrease, update pPos
                    if(!neg_peak) {pPos = i-1; neg_peak = true;}
                    res += --peak;
                }
            }
// don't forget to update res, if the last one is a local dip
            return !neg_peak? res : res - (peak-1) * (i-pPos - (peak>0));
    
        }
    };