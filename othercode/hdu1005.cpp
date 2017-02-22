#include <iostream>
using namespace std;

int main()
{
    int a,b,n;
    int f[50];
    f[1] = 1;
    f[2] = 1;
    while(cin>>a>>b>>n)
    {
        if(a == 0 && b==0 && n==0) break;

        for(int i=3;i<=49;i++)
        {
            f[i] = (a*f[i-1]+b*f[i-2])%7;
        }
        cout << f[n%49] << endl;
    }
}
