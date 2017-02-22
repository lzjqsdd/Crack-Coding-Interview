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
