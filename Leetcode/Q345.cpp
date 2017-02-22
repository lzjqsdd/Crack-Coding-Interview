#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
/**
* 题意容易理解错，这道题意思是字符串中出现的所有的原音字母进行reverse，就是全部颠倒，
* 如果有5个原音，那么五个反转再填充到原有的位置。
* 很容易理解为不断交换两个元音字母，例子库略坑爹
* 用map记录，但是map是默认字母序，所以会打乱顺序，使用vector
* 大写也算。。。
*/

int main()
{
    /*
    string s = "leetcode";
    set<char> vow = {'a', 'e', 'i', 'o', 'u'};
    int pos = 0, i = 0;
    for (i = 0; i < s.size(); ++i)
    {
        if (vow.find(s[i]) != vow.end()) //had find vowel
        {
            pos = i;
            break;
        }
    }
    for (;i < s.size(); ++i)
    {
        if (vow.find(s[i]) != vow.end())
        {
            //swap
            char tmp = s[i];
            s[i] = s[pos];
            s[pos] = tmp;
            pos = i;
        }
    }
    cout << s << endl;
    */
    string s = "beautifulgirl";
    set<char> vow = {'a', 'e', 'i', 'o', 'u'};
    vector<int> pos;
    vector<char> ch;
    for(int i=0;i<s.size();++i)
    {
        if (vow.find(s[i]) != vow.end()) //had find vowel
        {
            pos.push_back(i);
            ch.push_back(s[i]);
        }
    }
    vector<int>::iterator itp= pos.begin();
    vector<char>::reverse_iterator itc= ch.rbegin();
    for(;itp!=pos.end() && itc!=ch.rend();++itp,++itc)
    {
        s[*itp] = *itc;
    }
    cout << s << endl;
}