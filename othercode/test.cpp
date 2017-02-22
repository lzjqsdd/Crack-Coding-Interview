#include <iostream>
using namespace std;

int main()
{
    int a,b,n;
    while(cin>>a>>b>>n)
    {
        if(a == 0 && b==0 && n==0) break;

        int f1 = 1,f2=1;
        if(n == 1) cout << 1 << endl;
        else if(n == 2) cout << 1 << endl;
        else
        {
            for(int i=3;i<=n;i++)
            {
                int f = (a*f2+b*f1)%7;
                f1 = f2;
                f2 = f;
                cout << f2 << endl;
            }
        }
    }
}
