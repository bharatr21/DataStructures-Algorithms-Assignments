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
			if(!strcmp(inp, "N")) g[i][j] = INF;
			else { g[i][j] = atoi(inp);}
		}
	}

	f(i,0,n)
	{
		g[i][i] = 0;
	}

	f(i,0,n)
	{
		f(j,0,n)
		{
			d[i][j] = g[i][j];
		}
	}

	f(k,0,n)
	{
		f(i,0,n)
		{
			f(j,0,n)
			{
				if(d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	//Negative weight cycle
	f(i,0,n)
	{
		if(d[i][i] < 0) { printf("1\n"); return 0; }
	}
	printf("0\n");
	return 0;
}
