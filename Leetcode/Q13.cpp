#include <string>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    string  s = "CMXCIX";
    map<char,int> value{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    map<char,int> level{{'I',1},{'V',2},{'X',3},{'L',4},{'C',5},{'D',6},{'M',7}};

    if(s.size() == 0) return 0;
    int sum = value[s[s.size()-1]];
    for(int i=s.size()-2;i>=0;i--)
    {
        if(level[s[i]] < level[s[i+1]]) //如果当前的比之前的level小，在左侧，要减
            sum -= value[s[i]];
        else
            sum += value[s[i]];
    }
    cout << sum << endl;
    return sum;

}