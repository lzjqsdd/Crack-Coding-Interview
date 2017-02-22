/*
 *实现字符串翻转比如 ABCDEF ->  DEFABC
 *出现的问题：char *s 和 char s[]的区别
 */

#include <stdio.h>

void ReverseString(char *s,int from ,int to)
{
	while(from<to)
	{
		char t = s[from];
		s[from++] = s[to];
		s[to--] = t;
	}
}

void Trans(char *s,int len,int n)
{
	ReverseString(s,0,n-1);
	ReverseString(s,n,len-1);
	ReverseString(s,0,len-1);
}

int main()
{
	char s[] = "ABCDEF";
	Trans(s,6,3);
	printf("%s\n",s);
}
