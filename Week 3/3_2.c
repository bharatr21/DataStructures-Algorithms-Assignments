#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int merge(int ar[], int l, int mid, int r)
{
    int a[mid-l+1], b[r-mid], invct=0, x, i;
    f(i,0,mid-l+1) a[i] = ar[l+i];
    f(i,0,r-mid) b[i] = ar[mid+1+i];
    int j=0,idx=l;
    i=0;
    while(i<mid-l+1&&j<r-mid)
    {
        if(a[i]<b[j])
        {
            ar[idx++] = a[i++];
        }
        else{
            invct+=mid-l-i+1;
            f(x,i,mid-l+1) printf("%d %d\n",mid+j+1, l+x);
            ar[idx++] = b[j++];
        }
    }
    while(i<mid-l+1)
        ar[idx++] = a[i++];
    while(j<r-mid)
        ar[idx++] = b[j++];
	return invct2;	
}

int mergesort(int ar[], int l, int r)
{
    int invct=0;
    int mid = (l+r)>>1;
    if(l<r) {
        invct = mergesort(ar,l,mid);
        invct += mergesort(ar,mid+1,r);
        invct += merge(ar,l,mid,r);
    }
    return invct;
}


int main()
{
    int n,c,i;
    scanf("%d",&n);
    int ar[n];
    f(i,0,n) scanf("%d",&ar[i]);
    c = mergesort(ar,0,n-1);
    printf("%d\n",c);
    return 0;
}
