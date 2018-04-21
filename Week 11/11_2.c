#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define MIN(a,b) ((a)<=(b)?(a):(b))
#define MAX(a,b) ((a)>=(b)?(a):(b))

int dp[1005][1005];
int v[1005];
int adj[1005][1005];
int n;

int solve(int r,int s)
{
	if(dp[r][s]!=-1)
		return dp[r][s];

	int ans=0;
	if(s) ans=v[r];
	f(i,0,n+1)
	{
		if(adj[r][i]==1)
		{
			if(s) ans+=solve(i,0);
			else ans+=MAX(solve(i,0),solve(i,1));
		}
	}
	dp[r][s]=ans;
	return ans;
}

int main()
{
	f(i,0,1001)
		f(j,0,1001)
			dp[i][j]=-1;
	scanf("%d",&n);
	f(i,1,n+1)
		scanf("%d",&v[i]);
	int x,y;
	f(i,0,n-1)
	{
		scanf("%d%d",&x,&y);
		adj[x][y]=1;
	}
	printf("%d ",MAX(solve(1,0),solve(1,1)));
	return 0;
}

