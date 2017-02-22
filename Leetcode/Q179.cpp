//给定一组整数，要求拼接在一起的数最大
//按照字典序排序，由大到小拼接

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string result; //注意去除000000
        for(int x:nums) result+=to_string(x);

    }
};

static bool cmp(const int &a,const int &b)
{
    string sa = to_string(a);
    string sb = to_string(b);
    string tmp1 = sa+sb;
    string tmp2 = sb+sa;
    return tmp1 > tmp2 ? tmp1:tmp2;
}

//526,52
//524,52