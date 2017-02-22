#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int solve(int i)
{
    int sum = 0;
    while(i!=0)
    {
        int m = i%10;
        sum += m*m;
        i = i/10;
    }
    return sum;
}

int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> history;
        while(true)
        {
            int s = solve(n);
            if(find(history.begin(),history.end(),s) != history.end()) //说明出现了
                break;
            cout << s << endl;
            if(s != 1)
            { 
                history.push_back(s); //计入出现的数
                n = s;
            }   
            else
            {
                cout << "happy" << endl;
                break;
            }
        }
    }
}