#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int find(string s,int start,int end,char target)
{
	for(int i=start;i<=end;i++)
		if(s[i]==target) return i;

	return -1;
}

int lenofsub(string s)
{
	int len = s.size();
	if(len==1)return 1;


	int start=0,l=1;
	int max=1;
	for(int i=1;i<len;i++)
	{
		int pos = find(s,start,i-1,s[i]);
//		cout<<s[pos]<<endl;
		if(pos == -1)
			l++;
		else
		{
			l=i-pos;
			start=pos+1;
		}

		if(l > max) max=l;
		cout<<i<<":"<<max<<endl;
	}

	return max;
}

int main()
{
	string c="abcdedfddfdcbdfgehtjgk";
	cout<<lenofsub(c)<<endl;
}

//=======================================================================
//上述方法每次判断有没有重复数字是通过遍历已经记录的子序列
//本方法使用hash,unoderded_set的方式，O(1)方法即可判断是否有
//寻找最长没有重复字母的子序列
//第二遍

//错误：如果出现重复，那么新的子串的位置的起点的并不是开始新的串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
		unordered_set<int> se;
		int curlen = 0;
		for(int i = 0;i<s.size();++i)
		{
			if(se.find(s[i]) == se.end()) //如果当前序列没有
			{
				se.insert(s[i]);
				curlen++;
			}
			else
			{
				result = max(result,curlen);
				curlen = 0;
				se.clear();
			}
		}
		return result;
    }
};


//修正，用map记录每个元素的位置，出现重复之后从map中去掉该元素，同事把新的元素加进来作为新的序列

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int maxlen = 0;
	   map<char,int> hash_pos;
	   int curlen = 0;
	   int startpos = 0;
	   for(int i=0;i<s.size();++i)
	   {
		   auto pos = hash_pos.find(s[i]);
		   if(pos == hash_pos.end())
		   {
			   hash_pos[s[i]] = i;
			   curlen++;
		   }
		   else
		   {
			   maxlen = max(maxlen,curlen);

			   //形成新序列
			   int curpos = pos->second;
			   while(startpos <= curpos )
			   		hash_pos.erase(s[startpos++]); //把重复元素之前的序列去掉
			   curlen = i - startpos + 1;
			   hash_pos[s[i]] = i; //当前这个元素加进来
		   }
	   }
	   return max(maxlen,curlen); //循环终止最后一个序列需要考察
    }
};