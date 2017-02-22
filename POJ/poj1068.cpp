/*
对于P序列，可以发现和右括号所在的位置与Pi的关系,Pi加上i即可得到右括号的位置，其余均为做括号
对于W序列，我们同样可以发现右括号的位置和序号的关系，通过出栈操作处理。匹配的左括号和右括号的序号的序号差+1即为之间间隔的括号对。
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>

using namespace std;
typedef struct seq {
	int index;
	int flag;
}S;

int main()
{
	int t,n,p;


	cin>>t;
	while(t--)
	{
		int s1[50]={0};
		stack<S> s2;
		S tmp1,tmp2;

		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>p;
			s1[p+i]=1;
		}

		tmp1.index=0;tmp1.flag=0;
		int k=0;
		s2.push(tmp1);

		for(int i=1;i<=2*n;i++)
		{
			tmp1.index=i;tmp1.flag=s1[i];
		
			tmp2 = s2.top();
			if(tmp1.flag==tmp2.flag) s2.push(tmp1);
			else
			{
				s2.pop(); k++;
				cout<<(i-tmp2.index+1)/2;
				if(k!=n) cout<<" ";
				else cout<<endl;
			}
			
		}

	}


}

