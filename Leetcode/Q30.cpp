//30. Substring with Concatenation of All Words
//题意：给定一个长字符串s,给定一组短字符串,这些短字符串长度均相等
//找出每个短字符串在长字符串中的起始索引。

//如果对于每个短单词挨个找，O(n^2)
//如果对每个短单词建立hashtable，滑动长字符串，则每个查询只要O(1),总复杂度O(n).

题意：给定一个字符串 S 和一个字符串数组 L，L 中的字符串长度都相等，找出 S 中所有的子串恰好包含 L 中所有字符各一次，返回子串的起始位置。


//该版本理解出问题。
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_set<string> ss;
        for(auto w:words) ss.insert(w);
        int len = words[0].size();
        vector<int> result;
        for(int i = 0;i+len<s.size();++i)
        {
            if(ss.find(s.substr(i,len) != ss.end())
                result.push_back(i);
        }
        return result;
    }
};


//L中字符串可能重复
解决该问题的关键是理解清楚要求。 
给定一个目标字符串 s，一个单词集合 words。 
要求使得 words 集合中所有元素连续出现在 s 中的首位置组成的集合（元素顺序不考虑）。

正如所给实例，目标字符串 s: “barfoothefoobarman” 
对比单词集合 words: [“foo”, “bar”] 
我们发现，在 pos=0 ~ 5 时 “barfoo” 恰好匹配，则 0 压入结果 vector； 
在 pos=9 ~ 14 时 “foobar” 恰好匹配，则 9 压入结果 vector；

在理清楚题意后，便可入手程序实现。

//思路：hashmap<string,int> 统计L中的每个单词的个数。另开一个hashtable记录当前以及匹配的记录
//如果当前统计的元素不够，继续统计。如果比L还多了，则清空统计清空并移动窗口重新统计。
//从s开始找，找到连续的字符串包含了L中所有的元素，则index加入结果。
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int num = words.size();
        if(num == 0) return {};
        int slen = s.size(),wlen = words[0].size();
        if(slen < wlen * num) return {}; //s不够长
        unordered_map<string,int> m1;
        vector<int> result;

        for(auto w:words) m1[w]++; //统计L中每个单词的个数
        for(int i=0;i+num*wlen-1 < slen;i++)
        {
            unordered_map<string,int> m2;
            int j = 0;
            for(j = 0;j<num;++j) //往下走num个单词
            {
                string stmp = s.substr(i+j*wlen,wlen);
                if(m1.find(stmp) != m1.end()) //如果L中有这个子串
                {
                    m2[stmp]++;
                    if(m2[stmp] > m1[stmp]) break;
                }
                else break;
            }
            if(j == num) result.push_back(i);
        }
        return result;

    }
};

"barfoothefoobarman"
["foo","bar"]
"barfo"
["foo","bar"]
"foobar"
["",""]