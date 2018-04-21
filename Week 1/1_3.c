#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

int main()
{
	char s[100];
	int ch[256]={0};
	int i,lt;
	scanf("%[^\n]s",s);
	lt = strlen(s);
	f(i,0,lt)
	{
		ch[s[i]]++;
	}
	f(i,0,256)
	{
		if(ch[i])
		{
			printf("%c %d\n",i,ch[i]);
		}
	}
	return 0;
}