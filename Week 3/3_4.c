#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int check(int x, int a[], int n, int m)
{
	ll i, sum=0;
	f(i,0,n)
	{
		if(a[i]>=x) sum+=x;
		else sum+=a[i];
	}
	if(sum>=m*x) return 1;
	return 0;
}

int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	int a[n];
	ll sum=0;
	f(i,0,n) { scanf("%d",&a[i]); sum+=a[i]; }
	int l=0, r=sum+1, ans, mid;
	while(l<r){
		mid = (l+r)>>1;
		if(check(mid,a,n,m)) {ans=mid; l=mid+1;}
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
