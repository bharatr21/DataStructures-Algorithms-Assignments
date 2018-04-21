#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int bitcnt(int n)
{
	int ct=0;
	while(n)
	{
		if(n&1) ct++;
		n>>=1;
	}
	return ct;
}

int hasher(char* s)
{
	int sum=0,ans,i;
	int l = strlen(s);
	f(i,0,l) sum+=(int)s[i];
	ans = bitcnt(sum);
	return ans;
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	char s[n][1001];
	int a[33][n+1], b[33];
	f(i,0,33)
	{
		f(j,0,n+1)
		{
			a[i][j]=-1;
		}
	}
	f(i,0,33) b[i]=0;
	f(i,0,n) 
	{
		scanf("%s",s[i]);
		a[hasher(s[i])][b[hasher(s[i])]]=i;
		++b[hasher(s[i])];
	}
	printf("-------------------------------------------\n");
	f(i,0,33)
	{
		f(j,0,n+1)
		{
			if(a[i][j]!=-1) {
				printf("%s %d\n",s[a[i][j]],i);
				printf("\n");
			}	
		}
	}
	return 0;
}