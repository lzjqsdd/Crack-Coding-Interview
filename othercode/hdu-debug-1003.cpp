/*
 * 计算含+-* /的表达式
 */
#include <iostream>
#include <string>
#include <stack>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int t;
    string s;
    scanf("%d\n",&t);
    while(t--)
    {
	vector<int> numv;
	vector<char> operv;
        stack<int> nums;
        stack<char> opers;

	getline(cin,s);
        int x = 0;
        for(int i=0;i<s.size();i++)
        {
		if(s[i]>='0' && s[i]<='9')
			x=x*10+s[i]-'0';
		else
		{
			numv.push_back(x);
			x = 0;
			operv.push_back(s[i]);
		}
	}
	numv.push_back(x);

	opers.push('#');
	for(int i=0;i<numv.size();i++)
	{
		char tmpop = opers.top();
		if(tmpop == '#' || tmpop == '+')
		{
			nums.push(numv[i]);
			if(i < operv.size())
				opers.push(operv[i]);
		}
		else if(tmpop == '-')
		{
			opers.pop();
			opers.push('+');
			nums.push(-1*numv[i]);
			if(i < operv.size())
				opers.push(operv[i]);
		}
		else
		{
			int n1 = nums.top(); nums.pop();
			char op = opers.top(); opers.pop();
			int n2 = numv[i];
			int tmp;
			if(op == '*')  tmp = n1*n2;
			else tmp = n1/n2;
			nums.push(tmp);
			if(i < operv.size())
				opers.push(operv[i]);
		}
	}


	while(nums.size() > 1)
	{
		int n1 = nums.top(); nums.pop();
		int n2 = nums.top(); nums.pop();
		int op = opers.top(); opers.pop();
		int tmp;
		if(op == '+') tmp = n1+n2;
		else tmp = n2 - n1;
		nums.push(tmp);

	}
	cout << nums.top() << endl;

    }
}

