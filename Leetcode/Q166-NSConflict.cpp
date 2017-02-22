#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//存储每一步的除数，如果出现相同，则从该下标开始到最后的为循环段。
//返回vector下标可以使用迭代器it减去vector.begin()
string solve(int m,int n)
{
    if(n == 0) return  "";
    if(m == 0) return "0";

    int sign = 1;
    long mm = m,nn = n;
    if((m > 0 && n < 0) || (m<0 && n > 0) ){
        sign = -1; //记录符号
        mm = abs(mm);
        nn = abs(nn);
    }
    string result = "";
    vector<long> vn;
    vn.push_back(mm);

    //先处理小数点前的部分
    string prefix="";
    while(mm >= nn)
    {
        prefix.append(1,'0'+mm/nn);
        mm = mm % nn;
    }

    if(prefix == "") prefix = "0.";
    else prefix.append(1,'.');

    while(mm!=0)
    {
        while(mm < nn)
        {
            result+="0";
            mm*=10;
            vn.push_back(mm);
        }
        vn.push_back(mm);
        result.append(1,mm/nn+'0');
        mm = mm%nn;

        if(mm == 0) break; //余数为0，终止。

        auto it = find(vn.begin(),vn.end(),mm);
        if(it != vn.end()) //如果除数出现过
        {
            result = prefix+result.substr(0,it-vn.begin()) + "("+result.substr(it-vn.begin())+")";
            break;     
        }
    }

    return result;
}

int main()
{
    int m,n;
    while(cin >> m >> n)
        cout << solve(m,n) << endl;
}