#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int cmp(const void* a, const void* b)
{
	return *(int*) a - *(int*) b;
}

int min(int x, int y) { return ((x<y)?x:y); }

void swap(int* a, int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int* a, int l, int r, int pivot)
{
	int n=r-l+1, i, j;
	i=l-1;
	f(j,l,r+1)
	{
		if(a[j]<=pivot) {
			swap(&a[j],&a[i+1]);
			i++;
		}
	}
	return i;
}

int getkth(int* a, int l, int r, int k)
{
	int size=r-l+1;
	int i, buckets = (size+4)/5, j;
	int tarr[buckets],temp=0;
	for(i=l;i<=r;i+=5)
	{
		j=min(i+4,r);
		qsort(a+i,5,sizeof(a[0]),cmp);
		tarr[temp++]=a[(i+j)/2];
	}
	int mom = getkth(tarr, 0, temp-1, (temp+1)/2);
	int p = partition(a,l,r,mom);
	int ppos = p-l+1;
	if(ppos==k)
		return a[p];
	else if(k<ppos)
	{
		return getkth(a,l,p-1,k);
	}
	else return getkth(a,p+1,r,k-ppos);
}

int main()
{
	int n,ans,i;
	scanf("%d",&n);	
	int a[n];
	f(i,0,n)  scanf("%d",&a[i]);
	if(n&1)
	{
		ans=getkth(a,0,n-1,(n+1)/2);
	}
	else ans=(getkth(a,0,n-1,n/2)+getkth(a,0,n-1,(n+2)/2))/2.0;
	printf("%d ",ans);
	return 0;
}