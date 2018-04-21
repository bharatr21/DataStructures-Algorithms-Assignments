#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int max(int x,int y) { return ((x>y)?x:y); }

int main()
{
	int n,l,r,tm,i;
	scanf("%d",&n);
	scanf("%d %d",&l,&r);
	tm=l;
	printf("%d ",tm);
	++tm;
	f(i,0,n-1)
	{
		scanf("%d %d",&l,&r);
		if(tm>r) printf("0 ");
		else
		{
			tm=max(tm,l);
			printf("%d ",tm);
			++tm;
		}
	}
	printf("\n");
	return 0;
}
