#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

void merge(int ar[], int l, int mid, int r)
{
	int a[mid-l+1], b[r-mid],i;
	f(i,0,mid-l+1) a[i] = ar[l+i];
	f(i,0,r-mid) b[i] = ar[mid+1+i];
	int j=0,idx=l;
	i=0;
	while(i<mid-l+1&&j<r-mid)
	{
		if(a[i]<b[j])
			ar[idx++] = a[i++];
		else
			ar[idx++] = b[j++];
	}
	while(i<mid-l+1)
		ar[idx++] = a[i++];
	while(j<r-mid)
		ar[idx++] = b[j++];
}

void mergesort(int a[], int l, int r)
{
	if(l<r) {
		int mid=(l+r)>>1;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}

void builder(int ar[], int l, int mid, int r)
{
	int a[mid-l+1], b[r-mid],i;
	f(i,0,mid-l+1) a[i] = ar[l+i];
	f(i,0,r-mid) b[i] = ar[mid+1+i];
	int j=0, k1=l, k2=mid+1, it=1;
	i=0;
	while(i<mid-l+1)
	{
		if(it)
		{
			it=0;
			ar[k1++]=a[i++];
		}
		else{
			it=1;
			ar[k2++]=a[i++];
		}
	}
	it=1;
	while(j<r-mid)
	{
		if(it)
		{
			it=0;
			ar[k1++]=b[j++];
		}
		else{
			it=1;
			ar[k2++]=b[j++];
		}
	}
}

void build(int a[], int l, int r)
{
	if(l<r) {
		int mid=(l+r)>>1;
		builder(a,l,mid,r);
		build(a,l,mid);	
		build(a,mid+1,r);
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	f(i,0,n) scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	build(a,0,n-1);
	f(i,0,n) printf("%d ",a[i]);
	printf("\n");
	return 0;
}
