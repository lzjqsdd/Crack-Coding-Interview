//对x开方
#include <iostream>
#include <cmath>
using namespace std;


int Sqrt(int x,int s,int t)
{
    if(s - t == 1) return t; //递归出现s-t = 1的情况，说明找不到，此时t*t < x ,s*s > x,返回小的
    //if(t*t < x) return t; //说明找不到
    long mid = s+(t-s)/2; //乘法溢出
    if(mid * mid == x)
        return mid;
    else if(mid*mid > x)
        return Sqrt(x,s,mid-1);
    else
        return Sqrt(x,mid+1,t);   
}


int main()
{
    int n;
    while(cin >> n)
        cout << Sqrt(n,0,n) << endl;
}