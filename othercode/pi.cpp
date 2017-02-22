#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<climits>

using namespace std;

#define NUM 10001
#define MAX 40000

int cost[NUM];

int calc(string s,int a,int b)
{
	string M=s.substr(a,b-a+1);
	if(M==string(M.size(),M[0])) return 1;

	int i;
	bool flag=true;
	for(i=1;i<M.size()-1;i++)
		if(M[i+1]-M[i]!=M[i]-M[i-1]) 
		{flag=false;break;}

	if(flag==true&&i==M.size()-2)
	{
		if(abs(M[1]-M[0])==1) return 2;
		else return 5;
	}
	
	bool flag2=true;
	for(i=0;i<M.size()-2;i++)
		if(M[i]!=M[i+2])
		{
			flag2=false;
			break;
		}
	if(flag2&&i==M.size()-3) return 4;

	return 10;
}

int min(int a,int b)
{
	return a<b?a:b;
}

void solve(string s,int pos)
{
	int minv = MAX;
	int tmp;
	for(int l=3;l<=5;l++)
	{
		if(pos-l+1>=0)
		{
			tmp = calc(s,pos-l+1,pos);
			cout<<"calc pos:"<<pos<<"value"<<tmp<<endl;
			minv = min(minv,tmp+cost[pos-l+1]);
		}
	}
	cost[pos]=minv; 
}


int main()
{
	int n;
	string s;
	cin>>n;
	while(n--)
	{
		cin>>s;
		cost[0]=cost[1]=0;
		for(int i=2;i<s.size();i++)
			solve(s,i);
//		for(int i=0;i<s.size();i++)
//			cout<<cost[i]<<endl;
		cout<<cost[s.size()-1]<<endl;
	}
	return 0;
}
