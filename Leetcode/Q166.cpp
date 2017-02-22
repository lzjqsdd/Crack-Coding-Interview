#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//本题主要处理的是小数部分，分为整数部分prefix,和 小数部分suffix。
//每次都把补0后的数存储到vn中。
//存储每一步的除数，如果出现相同，则从该下标开始到最后的为循环段。
//返回vector下标可以使用迭代器it减去vector.begin()
string solve(int m,int n)
{

    //处理特殊情况和符号
    if(n == 0) return  "";
    if(m == 0) return "0";
    int sign = 1;
    long mm = m,nn = n;
    if((m > 0 && n < 0) || (m < 0 && n > 0)){
        sign = -1; //记录符号
    }
    mm = abs(mm);
    nn = abs(nn);

    //先处理小数点前的部分
    string prefix="";
    if(mm >= nn){
        prefix = to_string(mm/nn); //大于0的可以直接用求模运算
        mm = mm % nn;
    }


    //处理小数部分
    vector<long> vn;
    string suffix = "";

    while(mm!=0)
    {
        auto it = find(vn.begin(),vn.end(),mm);
        if(it != vn.end()) //如果出现过，直接跳出
        {
            int index = it - vn.begin();
            suffix = suffix.substr(1,index-1) + "(" + suffix.substr(index) + ")";
            break;
        }

        vn.push_back(mm);
        suffix.append(1,'0'+mm/nn); //不够除就是0，够除是个0~9的商。
        mm = mm%nn;
        mm*=10; //补一位
    }
    if(mm == 0 && suffix!="") suffix = suffix.substr(1);

    if(prefix == "") prefix = "0";

    if(suffix!="") suffix = "."+suffix;

    string result = prefix+suffix;
    if(sign == -1) result = "-"+result;

    return result;
}

int main()
{
    int m,n;
    while(cin >> m >> n)
        cout << solve(m,n) << endl;
}
