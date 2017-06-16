//题意:给定一个字符串，只有小写字母，可能包含多个重复的字母，通过移除字母，使得剩下的字母都唯一，并且字典序最小。
//要求字典序最小，那么尽可能让字母小的放在前面。所以在移除的过程中，如果前面有较大的字母，并且该字母有多个，显然可以移除当前这个，
//保留后面的那个。如果当前字母已经确定被保留下来，则剩下的都移除。如果字母个数只有一个，只能保留。
/*
class Solution
{
  public:
    string removeDuplicateLetters(string s)
    {
        map<char, int> count;
        for (char c : s)
            count[c]++;
        string result = "";
        //s.append(1, s.back()); //设置哨兵和最后一个相同
        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (count[s[i]] == 1)
            {
                result.append(1, s[i]);
                count[s[i]] = -1;
            }
            else if (count[s[i]] > 1)
            {
                //移除当前
                if (s[i] > s[i + 1])
                    count[s[i]]--;
                else
                {
                    result.append(1, s[i]);
                    count[s[i]] = -1;
                    //标记
                }
            }
            //count[s[i]] = -1表示已经被选择过了不再考虑
        }
        return result;
    }
};

//WA
"bcabc"
*/

//贪心算法，从最优结果的形式出发，然后缩小最优的问题的规模。
//假设最有答案的序列的最小值为s[i],则s[i]之前的都应该被移除掉，s[i]之后的和s[i]相同的也应该被移除掉。
//此时不考虑s[i],问题规模缩小到i+1~n之后的序列最优的求解上。并且s[i]之前的对子问题也并无干扰。


//考虑什么样的s[i]是我们要选择的呢？从序列开始遍历，第一次出现并且统计中只有一个，不得不选。或者从序列开始每个字符都出现x`多次但是还不是当前最小的
//字符，显然可以忽略当前出现的这些，往后选小的。
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
  public:
    string removeDuplicateLetters(string s)
    {
        map<char, int> count;
        for(auto it = s.begin();it!=s.end();++it)
        {
            while(it+1 != s.end() && *(it+1) == *it) s.erase(it+1);
        }
        for (char c : s) count[c]++;
        string result = "";
        for(int i = 0; i < s.size(); ++i)
        {
            if(count[s[i]] == 0) continue;
            int mini = i;
            if(count[s[i]] > 1)
            {
                int j = mini+1;
                while(j < s.size())
                {
                    if(count[s[j]] == 0) {j++;continue;}
                    if(s[j] < s[mini]) mini = j;
                    else break;
                    if(count[s[j]] == 1) break;
                    j++;
                }
            }
            cout << "mini:" << mini << endl;
            //第一个元素为s[j]
            result.append(1,s[mini]); count[s[mini]] = 0; //选择后就不再考虑了。
            for(int k=i;k<mini;++k) count[s[k]]--;
            i = mini;
        }
        return result;
    }
};

int main()
{
    Solution s;
    string test = "cbbbcaa";
    cout << s.removeDuplicateLetters(test) << endl;
}


/*
"bcabc"
"cndhadnnccdacde"
"anbccbddcnde"
"a"
"aaa"
"aaabccca"
"ddddeee"
"bbcaac";
"cbbbcaa"
*/



///==============
//http://www.cnblogs.com/grandyang/p/5085379.html
这道题让我们移除重复字母，使得每个字符只能出现一次，而且结果要按字母顺序排，
前提是不能打乱其原本的相对位置。我们的解题思路是：先建立一个哈希表来统计每个字母出现的次数，
还需要一个 visited 数字来纪录每个字母是否被访问过，我们遍历整个字符串，对于遍历到的字符，
先在哈希表中将其值减一，然后看 visited 中是否被访问过，若访问过则继续循环
，说明该字母已经出现在结果中并且位置已经安排妥当。如果没访问过，
我们和结果中最后一个字母比较，如果该字母的 ASCII 码小并且结果中的最后一个字母在哈希表中的值不为 0(说明后面还会出现这个字母)，
那么我们此时就要在结果中删去最后一个字母且将其标记为未访问，然后加上当前遍历到的字母，并且将其标记为已访问，
以此类推直至遍历完整个字符串 s，此时结果里的字符串即为所求。这里有个小技巧，
我们一开始给结果字符串 res 中放个 "0"，就是为了在第一次比较时方便，
如果为空就没法和 res 中的最后一个字符比较了，而‘0’的 ASCII 码要小于任意一个字母的，
所以不会有问题。最后我们返回结果时再去掉开头那个‘0’即可，参见代码如下：


#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
  public:
    string removeDuplicateLetters(string s)
    {
        unordered_map<char,int> dict;
        for(auto c:s) dict[c]++;
        vector<char> visited(128,0);
        string result = "0";
        for(char c:s)
        {
            dict[c]--;
            if(!visited[c]) //如果该字母未加入结果
            {
                while(dict[result.back()] != 0 && result.back() > c)
                {
                    visited[result.back()] = 0;
                    result.pop_back();
                }
                result+=c;
                visited[c] = 1;
            }
        }
        return result.substr(1);
    }
};