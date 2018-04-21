#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

int main()
{
	ll A[10][10], B[10][10];
	int m,n,p,i,j,k;
	scanf("%d%d",&m,&p);
	f(i,0,m)
	{
		f(j,0,p)
		{
			scanf("%lld",&A[i][j]);
		}
	}
	scanf("%d%d",&p,&n);
	f(i,0,p)
	{
		f(j,0,n)
		{
			scanf("%lld",&B[i][j]);
		}
	}
	int sum=0;
	f(i,0,m)
	{
		f(j,0,n)
		{
			f(k,0,p)
			{
				sum+=(A[i][k]*B[k][j]);
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}