#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

int main()
{
	ll n,ct=0;
	scanf("%lld",&n);
	while(n)
	{
		if(n&1) ct++;
		n>>=1;
	}
	printf("%lld\n",ct);
	return 0;
}