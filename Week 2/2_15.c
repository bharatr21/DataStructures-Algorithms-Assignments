#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

ll po(int base,int exp)
{
	ll ans=1;
	while(exp)
	{
		if(exp&1) ans*=base;
		base=base*base;
		exp>>=1;
	}
	return ans;
}

int digits(int num)
{
	int d=0;
	ll temp=num;
	while(temp)
	{
		d++;
		temp/=10;
	}
	return d;
}

int main()
{
	int i,n,dig,k;	
	printf("Enter initial seed\n");
	scanf("%d",&n);
	printf("Enter no of random numbers required\n");
	scanf("%d",&k);
	int temp=n;
	while(temp)
	{
		dig++;
		temp/=10;
	}	
	ll sq=n*n,temp1;
	printf("%d random numbers with the seed %d are\n",k,n);
	f(i,0,k)
	{
		int temp1 = digits(sq);
		sq%=po(10, temp1-(temp1/4));
		sq/=po(10, temp1-(temp1/4)-dig);
		printf("%lld\n",sq);
		sq = sq*sq;
	}
	return 0;
}