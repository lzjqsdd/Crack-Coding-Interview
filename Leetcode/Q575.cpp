//题意：分糖果，给定一个数组，这个数组中每个数字代表糖果的类别，数组元素为偶数个，要求给两个人各一半，
//求这两个人中分到糖果种类最多的结果。


//思路：尽可能给其中一个人分配不同种类的糖果。
//hashtable，统计糖果的种类k，如果种类k小于n/2,则其中一个人最多有k个
//如果糖果种类k >= n/2，则最多有n/2个

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> s;
        for(auto ca:candies) s.insert(ca);
        int k = s.size():
        if(k >= candies.size() / 2) return candies.size()/2;
        else return k;
    }
};