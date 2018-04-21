#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int min(int a, int b) { return ((a < b) ? a : b); }

int find(int n, int st, int p[][n])
{
	int end = n-1, i;
	fd(i,end,st)
	{
		if(p[st][i])
			break;
	}
	return i;
}

void minPalPartition(int n, char* str, int p[][n])
{
	int c[n];
	int i,j,k,l, st, end = 0;
	f(i,0,n)
	{
		p[i][i] = 1;
	}
	f(l,2,n+1)
	{
		f(i,0,n-l+1)
		{
			j = i + l - 1;
			if(l == 2)
				p[i][j] = (str[i] == str[j]);
			else
				p[i][j] = (str[i] == str[j]) && (p[i+1][j-1]);
		}
	}
	f(i,0,n)
	{
		if(p[0][i]) 
			c[i] = 0;
		else
		{
			c[i] = 999;
			f(j,0,i)
			{
				if( (p[j+1][i]) && (1 + c[j] < c[i]) )
					c[i] = 1 + c[j];
			}
		}
	}
	printf("%d, ",1 + c[n-1]);
	st = 0;	
	/*f(i,0,n)
	{
		f(j,0,n)
		{
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}*/
	while(end < n - 1)
	{
		end = find(n, st, p);
		f(i,st,end + 1)
		{
			printf("%c",str[i]);
		}	
		st = end + 1;
		if(end != n-1) printf(", ");
	}
	printf("\n");
}

int main()
{
	char s[100];
	scanf("%s",s);
	int n = strlen(s);
	int p[n][n];
	memset(p, 0, sizeof(p[0][0])*n*n);
	minPalPartition(n, s, p);
	return 0;
}
