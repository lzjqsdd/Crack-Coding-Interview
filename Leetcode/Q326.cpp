#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
        int n;
        cin >> n;
        double x =  log(n) / log(3);
        cout << x << endl;
        return  x == (int)x ? true : false;
}