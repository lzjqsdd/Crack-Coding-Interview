//sell stock (multi trade)
//buy[i] 表示第i天状态保持为买入获得的最大的利益
//sell[i] 表示第i天状态保持为卖出获得的最大的利益
//第i天不操作，则第i天的利益为 opt[i-1]
//opt[i] 表示第i天获得的最大的利益

//buy[i] = opt[i-1] - prices[i];
//sell[i] = prices[i]+buy[i-1];

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy,sell;
        sell = prices[0]; //Error初始化条件错误 sell = 0;第一个sell应该是0;
        buy = -prices[0];
        for(int i=1;i<prices.size();++i)
        {
            int tmpS = sell;
            int tmpB = buy;
            sell = max(prices[i] + tmpB,tmpS);
            buy = max(tmpS - prices[i],tmpB);
        }
        return max{sell,buy};
    }
};

//[3,6,5,2,1,6,7,8,23,22,11,23,6,4]