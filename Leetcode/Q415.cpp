#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string num1 = "1111";
    string num2 = "99099";
    const int len = num1.size()>num2.size() ? num1.size()+1:num2.size()+1;
    string result(len,'0');
    cout << result << endl;
    int i = num1.size()-1;
    int j = num2.size()-1;
    int k = 0;
    while(i>=0 && j>=0)
    {
        int s = (num1[i--]-'0')+(num2[j--]-'0')+(result[k]-'0');
        int m = s%10;
        int qu = s/10;
        cout << "余数" << m << " 进位" << qu << endl;
        result[k++] = m+'0';
        result[k] = qu+'0';
    }
    while(i>=0)
    {
        int s = (num1[i--]-'0')+(result[k]-'0');
        int m = s%10;
        int qu = s/10;
        result[k++] = m+'0';
        result[k] = qu+'0'; //进位;
    }
    while(j>=0)
    {
        int s = (num2[j--]-'0')+(result[k]-'0');
        int m = s%10;
        int qu = s/10;
        result[k++] = m+'0';
        result[k] = qu+'0'; //进位;
    }
    if(result[k--] == '0') result.erase(result.end()-1);
    reverse(result.begin(),result.end());
    cout << result << endl;
 }