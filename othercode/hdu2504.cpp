#include <iostream>
#include <cmath>
using namespace std;

const double Err =  1e-10;

int main()
{
    double a,b;
    while(cin >> a >> b)
    {
        if(fabs(a-b) < Err)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

}
