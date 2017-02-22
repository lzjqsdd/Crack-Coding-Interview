#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>

//计算矩阵相乘 DP

using namespace std;
#define NUM 10
typedef struct matrix{
        int row;
        int col;
		int data[NUM][NUM];
}M; 
M mat[NUM];
int opt[NUM][NUM];
int s[NUM][NUM];
int n;

void input()
{
	int k,i,j;
	cin>>n;
	for(k=0;k<n;k++)
	{
		cin>>mat[k].row>>mat[k].col;
		for(i=0;i<mat[k].row;i++)
			for(j=0;j<mat[k].col;j++)
				cin>>mat[k].data[i][j];
	}

}

void solve()
{
	for(int i=0;i<n;i++)
		opt[i][i]=0;

	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			//cout<<i<<','<<j<<endl;
			opt[i][j] = INT_MAX;

			for(int k=i;k<=j-1;k++)
			{
				int step = opt[i][k]+opt[k+1][j]+mat[i].row*mat[k].col*mat[j].col;
				if(step<opt[i][j])
				{
					opt[i][j] = step;
					s[i][j] = k;
				}
			}
		}
	}

}

M calc(int i,int j)
{
	if(i==j) return mat[i];
	else
	{
		int pk = s[i][j];
		M mik = calc(i,pk);
		M mkj = calc(pk+1,j);

		M rm;
		rm.row = mik.row;
		rm.col = mkj.col;

		for(int i=0;i<rm.row;i++)
			for(int j=0;j<rm.col;j++)
			{
				rm.data[i][j] = 0;
				for(int k=0;k<mik.col;k++)
					rm.data[i][j]+=mik.data[i][k]*mkj.data[k][j];
			}
		return rm;
	}
}

int main()
{
	input();
	solve();

//	cout<<"result"<<opt[0][n-1]<<endl;

	M rtm = calc(0,n-1);

	for(int i=0;i<rtm.row;i++)
	{
		for(int  j=0;j<rtm.col;j++)
			cout<<rtm.data[i][j]<<" ";
		cout<<endl;
	}
    return 0;
}
