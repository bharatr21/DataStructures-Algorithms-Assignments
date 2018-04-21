#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define INF 10000000

int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(!n) return 0;
		int d[n+1][n+1];
		f(i,0,n+1)
		{
			f(j,0,n+1)
			{
				d[i][j] = INF;
			}
		}
		int x;
		char s[10];
		f(i,1,n+1)
		{
			scanf("%d %s",&x,s);
			if(s[0]=='t') d[i][x] = 2;
			else d[i][x] = 1;
		}
		f(k,1,n+1)
		{
			f(i,1,n+1)
			{
				f(j,1,n+1)
				{
					if(d[i][j] > d[i][k] + d[k][j])
						d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
		int flag = 0;
		f(i,1,n+1)
		{
			if(d[i][i] < INF/2 && (d[i][i]&1)) {
				printf("\nPARA");
				flag = 1;
				break;
			}
		}
		if(!flag)
			printf("\nNOT PARA");
	}
	return 0;
}
