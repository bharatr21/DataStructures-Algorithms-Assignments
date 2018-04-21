#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'
#define INF 999

int main()
{
	int n;
	scanf("%d",&n);
	int g[n][n], d[n][n];
	char inp[10] = "00";
	f(i,0,n)
	{
		f(j,0,n)
		{
			scanf("%s",inp);
			if(!strcmp(inp, "N")) g[i][j] = -INF;
			else { g[i][j] = atoi(inp);}
			d[i][j] = g[i][j];
		}
	}

	f(i,0,n)
	{
		g[i][i] = 0;
	}

/*	printf("\n");
	f(i,0,n)
	{
		f(j,0,n)
		{
			printf("%d ",g[i][j]);
		}
		printf("\n");
	}*/

	f(k,0,n)
	{
		f(i,0,n)
		{
			f(j,0,n)
			{
				if(d[i][k] + d[k][j] > d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
	
	int maxi=-999;
	f(i,0,n)
	{
		f(j,0,n)
		{
			if(maxi < d[i][j])
				maxi = d[i][j];
		}
	}
	printf("%d\n",maxi);
	return 0;
}
