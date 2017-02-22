//Best Time to Buy and Sell Stock with Cooldown
//类比Q122，卖完股票之后一天不能买入
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        vector<int> buy;
        vector<int> sell;
        sell.push_back(0); //sell[0] = 0,sell[1] = 
        sell.push_back(max(prices[1] - prices[0],0)); //卖出只有一种情况，day0买入，day1卖出
        buy.push_back(-prices[0]);
        buy.push_back(max(-prices[0],-prices[1])); //状态为买入，第一天买入或者第二天买入
        for(int i=2;i<prices.size();++i)
        {
            int s = max(prices[i] + buy[i-1],sell[i-1]);
            int b = max(sell[i-2] - prices[i],buy[i-1]);
            sell.push_back(s);
            buy.push_back(b);
        }
        return max(sell.back(),buy.back());
    }
};