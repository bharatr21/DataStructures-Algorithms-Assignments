#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

int main()
{
	ll c,n,p;
	scanf("%lld %lld %lld",&c,&n,&p);
	ll temp=n,ans=1;
	while(n)
	{
		if(n&1) ans=((ans%p)*(c%p))%p;
		c=((c%p)*(c%p))%p;
		n>>=1;
	}
	printf("%lld\n",ans);
	return 0;
}