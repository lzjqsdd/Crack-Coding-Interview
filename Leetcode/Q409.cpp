
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int longestPalindrome(string s) {
        int num[128]={0};
        int result = 0; 
        for(int i=0;i<s.size();i++)   num[s[i]]++;
        for(int i=0;i<128;i++) 
        {
            if(num[i]%2 == 1) { result=1; break;}
        }
        for(int i=0;i<128;i++) 
        {
            cout << num[i] << endl;
            result += ((num[i]/2) * 2);
        }
        return result;
}

int main()
{
    string s = "abccccdd";
    longestPalindrome(s);
}