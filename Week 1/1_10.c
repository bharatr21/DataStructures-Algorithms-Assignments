#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int multiply(int x, int* ans,int size)
{
	ll prod;
	ll carry=0,i;
	f(i,0,size) {
		prod = ans[i]*x+carry;
		ans[i] = prod%10;
		carry = prod/10;
	}
	while(carry)
	{
		ans[size] = carry%10;
		carry/=10;
		size++;
	}
	return size;
}

int main()
{
	int ans[36000];
	ll n,i,size;
	ans[0]=1;
	size=1;
	scanf("%lld",&n);
	f(i,1,n+1)
	{
		size = multiply(i,ans,size);
	}
	size--;
	fd(i,size,0) {
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}