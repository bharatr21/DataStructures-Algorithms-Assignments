#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

int main()
{
	int n,k,e,i,j,st,en,ct=0;
	scanf("%d%d",&n,&k);
	int g[n][n], vis[n];
	f(i,0,n) vis[i] = 0;
	f(i,0,n)
	{
		f(j,0,n)
		{
			scanf("%d",&g[i][j]);
		}
	}
	scanf("%d%d",&st,&en);
	int count[n][n][k+1];
	f(e,0,k+1)
	{
		f(i,0,n)
		{
			f(j,0,n)
			{
				count[i][j][e] = 0;
				if(e == 0 && i == j)
				{
					count[i][j][e] = 1;
				}
				if(e == 1 && g[i][j])
				{
					count[i][j][e] = 1;
				}
				if(e > 1)
				{
					f(a,0,n)
					{
						if(g[i][a])
						{
							count[i][j][e]+=count[a][j][e-1];
						}
					}
				}
			}
		}
	}
	printf("\n");
	f(e,0,k+1) printf("Exactly %lld edges: %d\n",e,count[st][en][e]);
	f(e,0,k+1) count[st][en][e]+=count[st][en][e-1]; //Cumulative
	printf("%d\n",count[st][en][k]);
	return 0;
}