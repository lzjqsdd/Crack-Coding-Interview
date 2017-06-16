//题意：给定一组表达式 ，求出这组表达式可能的结果（不含括号),不同组合的表达式计算结果可以重复

//Divide & Conquer

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums; //存放操作数
        vector<char> ops; //存放操作符
        istringstream in(input);
        int number;
        char oper;
        in >> number;
        nums.push_back(number);
        while(in >> oper >> number)
        {
            nums.push_back(number);
            ops.push_back(oper);
        }
        return DandC(nums,ops,0,nums.size()-1);
    }

    vector<int> DandC(vector<int>&nums,vector<char>&ops,int l,int r)
    {
        if(l == r) return vector<int>(1,nums[l]); //错在这里了，返回一个元素而vector<int>(n)表示是n个0,
        else
        {
            vector<int> res;
            for(int i=l;i<r;++i){
                vector<int> lres = DandC(nums,ops,l,i);
                vector<int> rres = DandC(nums,ops,i+1,r);
                
                //结合的操作数在切分点之后
                for(auto x:lres)
                    for(auto y:rres)
                    {
                        if(ops[i] == '+')
                            res.push_back(x+y);
                        else if(ops[i] == '-')
                            res.push_back(x-y);
                        else
                            res.push_back(x*y);
                    }
            }
            return res;
        }
    }
};

int main()
{
    string test = "1+2*3-4";
    vector<int> res = diffWaysToCompute(test);
    for(auto r:res) cout << res << endl;
}


[-153,-108,-108,-101,-93,-71,-71,-66,-61,-47,-47,-45,-27,-27,-25,-17,-12,-12,0,12,19,24,24,27,29,29,33,33,33,35,43,48,48,48,49,49,54,59,60,72,72,87]
[-61,-101,59,-71,49,-27,-47,29,33,-71,49,-17,19,43,-93,-153,87,-108,72,-27,-47,-25,-45,29,33,27,33,35,-66,54,-12,24,48,-108,72,-12,0,24,48,12,48,60]