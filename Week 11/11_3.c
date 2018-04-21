#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define INF 1000000

int n,m,x;
int clr[100][100];
int cnt[100];
int w[100];
int c[100];

int min(int a,int b) { return (a < b) ?a : b; }

int dp[100][100];

int solve(int id,int cap)
{
	int i;
	if(cap<0)
		return INF;
	if(id==m+1)
		return cap;
	if(dp[id][cap]!=-1)
		return dp[id][cap];
	int ans=INF;
	for(i=0;i<cnt[id];i++)
	{
		ans=min(ans,solve(id+1,cap-w[clr[id][i]]));
	}
	return dp[id][cap]=ans;
}

int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		memset(clr,0,sizeof(clr));
		memset(cnt,0,sizeof(cnt));
		memset(w,0,sizeof(w));
		memset(c,0,sizeof(c));
		memset(dp,-1,sizeof(dp));
		scanf("%d%d%d",&n,&m,&x);
		for(i=0;i<n;i++)
			scanf("%d",&w[i]);
		for(i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
			clr[c[i]][cnt[c[i]]++]=i;//Storing index of every occurence of color
		}
	    int ans=solve(1,x);
		if(ans==INF)
		{
			printf("%d\n",-1);
		}
		else
		{
			printf("%d\n",ans);
		}
	}
}
