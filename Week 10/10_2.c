#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

int merge(int ar[], int l, int mid, int r)
{
	int a[mid-l+1], b[r-mid], invct = 0;
	f(i,0,mid-l+1) a[i] = ar[l+i];
	f(i,0,r-mid) b[i] = ar[mid+i+1];
	int j = 0, i = 0, idx = l;
	while( i < mid - l + 1 && j < r - mid)
	{
		if(a[i] < b[j])
			ar[idx++] = a[i++];
		else 
		{
			invct += (mid-l-i+1);
			ar[idx++] = b[j++];
		}
	}
	while(i < mid-l+1)
		ar[idx++] = a[i++];
	while(j < r - mid)
		ar[idx++] = b[j++];
	return invct;
}

int mergesort(int ar[], int l, int r)
{
	int invct = 0;
	int mid = (l+r)>>1;
	if(l < r)
	{
		invct = mergesort(ar, l, mid);
		invct += mergesort(ar, mid+1, r);
		invct += merge(ar, l, mid, r);
	}
	return invct;
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	f(i,0,n) scanf("%d",&a[i]);
	printf("%d\n",mergesort(a, 0, n));
	return 0;
}
