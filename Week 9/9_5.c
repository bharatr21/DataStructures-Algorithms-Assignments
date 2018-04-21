#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)


static ll pg[78500];
static ll check[1000001];

ll findct(ll n)
{
	ll q[78500];
	ll ct = 0, ma = 0, midx = 0;
	f(i,0,78500)
	{
		if(pg[i])
		{
			while(n%pg[i] == 0)
			{
				n/=pg[i];
				q[i]++;
				if(q[i] > ma)
					{ ma = q[i]; midx = i; }
			}
		}
	}
	return ct;
}

void sieve(ll* pg, ll* check)
{
	memset(check, 1, sizeof(check[0]));
	ll i, j;
	f(i,2,1000)
	{
		if(check[i])
		{
			for(j=2;j*i<1000000;j++) {check[j*i] = 0;}
		}
	}
	ll k = 0;
	f(i,2,1000000)
	{
		if(check[i])
		{
			pg[k++] = i;
		}
	}
}

int main()
{
	ll a, b;
	scanf("%lld%lld",&a,&b);
	sieve(pg, check);
	f(i,a,b+1)
	{
		findct(i);
	}
	return 0;
}
