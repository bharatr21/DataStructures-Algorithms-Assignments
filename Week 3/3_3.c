#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int check(int sum, int a[], int n, int m)
{
	int np=1,i;
	int tsum = a[0];
	int start=0;
	f(i,0,n)
	{
		if(a[i]>sum)
			return 0;
	}	
	f(i,start,n-1)
	{
		if(tsum+a[i+1]>sum)
		{
			np++;
			tsum = 0;
		}
		tsum+=a[i+1];	
	}
	if(np<=m) return 1;
	else return 0;
}

int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	int* a = malloc(n*sizeof(int));
	int maxsum = 0;
	f(i,0,n) {
		scanf("%d",&a[i]);
		maxsum+=a[i];
	}
	int l=0, r=maxsum;
	while(l<=r)
	{
		int mid = (l+r)>>1;
		if(check(mid,a,n,m)) r = mid-1;
		else l = mid + 1; 
	}
	printf("%d\n",l);
	free(a);
	return 0;
}
