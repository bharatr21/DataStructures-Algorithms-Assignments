#include<stdio.h>
#include <stdlib.h>
#define mx 1000000001
#define ll long long int

struct mys
{
    ll t,l;
} a[100001];

typedef struct mys mys;

int myc(const void* a, const void* b) {
    return (*(mys*)a).l - (*(mys*)b).l;
}

int main()
{
    int i;
    ll t,l,n;
    ll wt,time,max_time=0, min_time=mx, small=0;
    scanf("%lld",&n);
    for(i=0;i<n;++i)
    {
        scanf("%lld%lld",&t,&l);
        a[i].t=t;
        a[i].l=l;
        if( t > max_time) {
            max_time=t;
        }
        if(t < min_time) {
            min_time=t;
            small=i;
        }
    }
    time = a[small].l + a[small].t;
    wt = a[small].l;
    a[small].l = 0;
    qsort(a, n, sizeof(a[0]),myc);
    while(time < max_time) {
        for(i=0;i<n;++i) {
            if(a[i].t <= time && a[i].l!=0) {
                break;
            }
        }
        time+=a[i].l;
        wt+=time-a[i].t;
        a[i].l=0;
    }
    for(i=0;i<n;++i) {
        if(a[i].l!=0) {
            time+=a[i].l;
            wt+=time-a[i].t;
        }
    }
    printf("%lld\n",wt/n);
    return 0;
}