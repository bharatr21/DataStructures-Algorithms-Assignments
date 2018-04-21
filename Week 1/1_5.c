#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'
#define MOD 10000000000

int main()
{
	unsigned int exp;
	scanf("%u",&exp);
	__uint128_t n=2,prod=1;
	while(exp)
	{
		if(exp&1)
			prod = ((prod%MOD)*(n%MOD))%MOD;
		exp>>=1;
		n=((n%MOD)*(n%MOD))%MOD;
	}
	printf("%llu\n",prod);
	return 0;
}