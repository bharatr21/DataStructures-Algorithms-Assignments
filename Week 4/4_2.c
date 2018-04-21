#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int bins(int a[], int key, int l, int r, int i)
{
	int mid;
	while(l<=r) {
		mid=(l+r)>>1;
		if((a[mid]==key)&&(mid!=i)) return 1;
		else if((a[mid]<key)) l=mid+1;
		else r=mid-1;
	}
	return 0;
}

int main()
{
	int n,x,i;
	scanf("%d%d",&n,&x);
	int a[n], key;
	f(i,0,n) scanf("%d",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	int fl=0;
	f(i,0,n)
	{
		if(a[i]>=x)
			break;
		else {
			key=x-a[i];
			if(bins(a,key,0,n-1,i))
			{	fl=1;
				break;
			}
		}
	}
	if(fl) printf("Yes\n");
	else printf("No\n");
	return 0;
}
