#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'
#define lim 1000006
/*int gcd(int a, int b)
{
	int temp1=a,temp2=b;
	a = max(temp1,temp2);
	b = min(temp1,temp2);
	if((b==1)||(a%b==0)) return a;
	else return gcd(b,a%b);
}
int min(int x, int y) return (x<y?x:y);
int max(int x, int y) return (x>y?x:y);
int lcm(int i, int n)
{
	return (n*i)/gcd(n,i);
}*/
ll totient[1000005], a[1000005]={0};
void totient_sum()
{
	int i,j;
	f(i,1,lim) totient[i]=i;
	f(i,2,lim)
	{
		if(totient[i]==i)
		{
			for(j=2*i;j<=lim;j+=i) totient[j]-=totient[j]/i;
		}
	}
	f(i,2,lim)
	{
		if(totient[i]==i) totient[i]=i-1;
	}
	f(i,1,lim)
	{
		for(j=i;j<=lim;j+=i)
			a[j]+=i*totient[i];
	}
}

int main()
{
	/*ll sum=0,n;
	scanf("%d",&n);
	f(i,1,n+1)
	{
		sum+=totient(i,n);
	}
	printf("%lld\n",sum);*/
	totient_sum();
	ll ans=0, n;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ans = (1+a[n])*n/2;
		printf("%lld\n",ans);
	}
	return 0;
}