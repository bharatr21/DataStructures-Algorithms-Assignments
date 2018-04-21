#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

struct el
{
    int idx;
    int freq;
};

typedef struct el el;

int cmp(const void* a, const void* b)
{
    if((*(el*)a).freq==(*(el*)b).freq)
        return (*(el*)a).idx - (*(el*)b).idx;
    else
        return (*(el*)b).freq - (*(el*)a).freq;
}

int main()
{
    int n,i,j;
    scanf("%d",&n);
    int a[10001]={0};
    el ar[10001];
    f(i,0,10001) {ar[i].freq=0;}
    f(i,0,10001) {ar[i].idx=99999;}
    f(i,0,n)
    {
        scanf("%d",&a[i]);
        if(ar[a[i]].freq==0) ar[a[i]].idx=i;
        ar[a[i]].freq++;
    }
    int tot = sizeof(ar)/sizeof(ar[0]);
    qsort(ar,tot,sizeof(ar[0]),cmp);
    f(i,0,tot)
    {
        f(j,0,ar[i].freq)
        {
            printf("%d ",a[ar[i].idx]);
        }
    }
    return 0;
}
