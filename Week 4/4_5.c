#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'


int fact(int n)
{
	int i=0, cnt=0;
	for(i=1;i*i<=n;i++) 
	{
		if(n%i==0)
		{
			cnt+=2;
		}
		if(i*i==n) --cnt;
	}
	return cnt;		
}

struct el
{
	int fac;
	int idx;
};

typedef struct el el;

int cmp(const void* a, const void* b)
{
	if((*(el*)a).fac==(*(el*)b).fac)
		return (*(el*)a).idx - (*(el*)b).idx;
	else
		return (*(el*)b).fac - (*(el*)a).fac;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	el ar[n];
	f(i,0,n) {
		scanf("%d",&a[i]);
		ar[i].idx=i;
		ar[i].fac=fact(a[i]);
	}
	qsort(ar,n,sizeof(ar[0]),cmp);
	f(i,0,n) printf("%d ",a[ar[i].idx]);
	printf("\n");
/*	f(i,0,n) printf("%d ",ar[i].fac);
	printf("\n");*/
	return 0;
}
