#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

ll costt(int n, int h[], int c[], int eq)
{
	ll cost=0, i;
	f(i,0,n)
	{
		cost+=abs(h[i]-eq)*c[i];
	}
	return cost;
}

int main()
{
	int n;
	int h[n+1];
	int c[n+1];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i;
		int maxh = 0;
		scanf("%d",&n);
		f(i,0,n) scanf("%d",&h[i]);
		f(i,0,n) scanf("%d",&c[i]);
		ll minc = 30001*n, cost=0;
		f(i,0,n)
		{
			cost = costt(n,h,c,h[i]);
			if(minc > cost) minc = cost;
		}
		printf("%lld\n", minc);
	}
	return 0;
}
