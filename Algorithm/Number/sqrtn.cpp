#include<iostream>  
using namespace std;  

int Pow(int x, int n)  
{  
    if (n == 1)  
        return x;  
    else if (n > 1)  
    {  
        int s;  
        int m = n / 2;  
        s = Pow (x, m);  
        if (n % 2 == 0)  
            return (s * s);  
        else  
            return (s * s * x);  
    }  
}  

int main()  
{  
    int x, n;  
    while (cin >> x >> n)  
    {  
        cout << Pow(x, n) << endl;  
    }  
    return 0;  
}  
