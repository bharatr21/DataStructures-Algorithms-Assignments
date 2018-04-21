#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

ll fac(ll n, int primes[]) {
	if(n==1) return 1;
	ll tem,i;
	int k=0;
	ll ans;
	int exp;
	while(n)
	{
		if(n%primes[k]==0)
		{
			printf("%d ",primes[k]);
			exp=0;
			tem = primes[k];
			while(n%tem==0)
			{
				exp++;
				tem=tem*primes[k];
			}
			tem/=primes[k];
			n=n/tem;
			ans*=exp;
			k++;
			if(n==1) break;
		}
		else
			k++;
	}
	return ans;
}

int main()
{
	ll n,a,b;
	scanf("%lld%lld%lld",&n,&a,&b);
	int i,j;
	int isprime[100001];
	isprime[0]=0; isprime[1]=0;
	f(i,2,100001) isprime[i]=1;
	int primes[9600];
	f(i,2,100001)
	{
		if(isprime[i])
		{
			for(j=2*isprime[i];j<100001;j+=isprime[i])
			{
				isprime[j]=0;
			}
		}
	}
	f(i,2,100001) printf("%d is prime: %d\n",i,isprime[i]);
	int k=0;
	f(i,2,100001)
	{
		if(isprime[i])
		{
			primes[k++]=i;
		}
	}
	int ct=0;
	f(i,a,b+1)
	{
		if(fac(i,primes)==n) ct++;
	}
	printf("%d\n",ct);
	return 0;
}