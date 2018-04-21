#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

void merge(int ar[], int l, int mid, int r)
{
    int a[mid-l+1], b[r-mid], i;
    f(i,0,mid-l+1) a[i] = ar[l+i];
    f(i,0,r-mid) b[i] = ar[mid+1+i];
    int j=0,idx=l;
    i=0;
    while(i<mid-l+1&&j<r-mid) { 
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
    int mid;
    if(l<r)
    {
        mid=(l+r)>>1;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

int bins(int x,int a[], int l, int r)
{
    int mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(a[mid]==x && a[mid-1] < x) return mid;
        if(a[mid]<x) l=mid+1; 
        else r=mid-1;
    }
}

int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    int x[n], y[m], temp[n], ans[n], vis[n];
    f(i,0,n) { scanf("%d",&x[i]); temp[i]=x[i]; vis[i]=0; }
    f(i,0,m) scanf("%d",&y[i]);
    mergesort(temp,0,n-1);
    int idx=0,j=0;
    f(i,0,m)
    {
        idx = bins(y[i], temp, 0, n-1);
        while(temp[idx]==y[i])
        {
            ans[j++] = temp[idx];
            vis[idx]=1;
            idx++;
        }
    }
    f(i,0,n)
    {
        if(!vis[i])
            ans[j++]=temp[i];
    }
    f(i,0,n) printf("%d ",ans[i] );
    return 0;
}