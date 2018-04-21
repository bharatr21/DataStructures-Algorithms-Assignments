#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)

int max(int x, int y) { return (x > y) ? x : y; }

int profit(int n, int p[], int cache[][n], int be, int en)
{
	if(be > en) return 0;
	if(cache[be][en] != -1) return cache[be][en];
	int yr = n - (en-be+1) + 1;
	cache[be][en] = max( (profit(n, p, cache, be+1, en) + yr*p[be]) , (profit(n, p, cache, be, en-1) + yr*p[en]) );
	return cache[be][en];
}

int main()
{
	int n;
	scanf("%d",&n);
	int p[n];
	f(i,0,n) scanf("%d",&p[i]);
	int cache[n][n];
	memset(cache, -1, sizeof(cache[0][0])*n*n);
	printf("%d\n", profit(n, p, cache, 0, n-1));
	return 0;
}
