#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int cmp(const void* pa, const void* pb)
{
	char* a;
	char* b;
	a = (char* )pa;
	b = (char* )pb;
	int n1 = strlen(a);
	int n2 = strlen(b);
	if(n1<n2)
		return -1;
	else if(n1>n2)
		return 1;
	else{
		return strcmp(a,b);
	}
}

int main()
{
	char c[1000][1000];
	int n,i;
	scanf("%d",&n);
	f(i,0,n)
	{
		scanf("%s",c[i]);
	}
	qsort(c,n,sizeof(c[0]),cmp);
	f(i,0,n)
	{
		printf("%s\n",c[i]);
	}
	return 0;
}
