#include <iostream>
#include <string>
using namespace std;


int main()
{
	string s;
	while(cin>>s)
	{
		int n = s.size();
		for(int len = 1;len<=n;len++)
		{
			if(n%len == 0)
			{
				int num = n/len;//表示有几段
				int flag = 0;
				string startS = s.substr(0,len);
				for(int i=1;i<num;i++)
				{
					if(startS != s.substr(len*i,len))
					{
						flag = 1;
						break;
					}
				}

				if(flag == 0)
				{
					cout<<num<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
