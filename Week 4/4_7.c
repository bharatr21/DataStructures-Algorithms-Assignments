#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int partition(int a[], int n)
{
	int i,j=0,k=0;
	int b[n], c[n];
	f(i,0,n)
	{
		if(a[i]&1)
		{
			b[k++]=a[i];
		}
		else
			c[j++]=a[i];
	}
	f(i,0,j) a[i]=c[i];
	f(i,j,n) a[i]=b[i-j];
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	f(i,0,n) scanf("%d",&a[i]);
	partition(a,n);
	f(i,0,n) printf("%d ",a[i]);
	printf("\n");
	return 0;
}