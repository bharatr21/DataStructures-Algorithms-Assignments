#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

int max(int a, int b) {return (a > b) ? a : b; }

void bargains(int n, int k)
{
	int opt[n+1][k+1];
	int res;
	f(i,1,n+1)
	{
		opt[i][1] = 1;
		opt[i][0] = 0;
	}
	f(j,1,k+1)
		opt[1][j] = j;
	f(i,2,n+1)
	{
		f(j,2,k+1)
		{
			opt[i][j] = 9999;
			f(x,1,j+1)
			{
				res = 1 + max(opt[i-1][x-1], opt[i][j-x]);
				if(res < opt[i][j])
					opt[i][j] = res;
			}
		}
	}
	printf("%d\n",opt[n][k]);
}

int main()
{
	int n, k;
	scanf("%d%d",&k,&n);
	bargains(n, k);
	return 0;
}
