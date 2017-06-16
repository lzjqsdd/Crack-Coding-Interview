//给定n，输出n个括号可能的组成形式。
#include <vector>
#include <iostream>
using namespace std;


//能够正常匹配的括号对在任意位置满足 l >= r;
//比如(())(),从左往右看总是左括号的数量总是不小于右括号的数量。
//用递归解决，在递归中处理如下集中情况
//如果 l > r ,则可以(1)继续扩展左括号,(2)继续扩展右括号
//如果 l == r, 只能扩展左括号。直到l = r = n,结束。

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> record;
        string result = "";
        generate(result,0,0,n,record);
        return record;
    }

    //如果result作为引用传递，则必须逐层删除结尾元素（回朔），如果值传递则内层变化不会影响调用层的数据
    //已测试
    void generate(string& result,int l ,int r ,int n,vector<string>&record)
    {   
        //cout << l << "," << r << endl;
        if(l == n && r == n){record.push_back(result);cout << result << endl;return;}
        else if(l == r) //前面部分已经完整匹配
        {
            result+="(";
            generate(result,l+1,r,n,record);
            result.erase(result.end()-1);
        }
        else if(l == n && r < n) //只剩下右侧括号
        {
            result+=")";
            generate(result,l,r+1,n,record);
            result.erase(result.end()-1);
        }
        else if(l < n && r < n) //左右数量不同
        {
            result+="(";
            generate(result,l+1,r,n,record);
            result.erase(result.end()-1);
            result+=")";
            generate(result,l,r+1,n,record);
            result.erase(result.end()-1);
        }
    }
};

int main()
{
    Solution s;
    cout << "-----------" << endl;
    s.generateParenthesis(0);
    cout << "-----------" << endl;
    s.generateParenthesis(1);
    cout << "-----------" << endl;
    s.generateParenthesis(2);
    cout << "-----------" << endl;
    s.generateParenthesis(3);
    cout << "-----------" << endl;
    s.generateParenthesis(4);
    cout << "-----------" << endl;
}
