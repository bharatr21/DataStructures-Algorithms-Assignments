#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int min(int x, int y)
{
    return x<y?x:y;
}

struct e
{
    int first;
    int sec;
};

typedef struct e e;

int cmp(const void* a, const void* b)
{
    return (*(e*)a).first - (*(e*)b).first;
}

int dcmp(const void* a, const void* b)
{
    return (*(e*)b).first - (*(e*)a).first;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n],vis[n], vis1[n];    
    f(i,0,n) vis[i]=0;
    e ar[n], ar1[n];
    f(i,0,n) {
        scanf("%d",&a[i]);
        ar[i].first = a[i];
        ar[i].sec = i;
        ar1[i].first = a[i];
        ar1[i].sec = i;
    }
    qsort(ar,n,sizeof(ar[0]),cmp);
    qsort(ar1,n,sizeof(ar[0]),dcmp);
    int ans=0,cycle;
    f(i,0,n)
    {
        if((vis[i])||(ar[i].sec==i))
            continue;
        cycle=0;
        int j=i;
        while(!vis[j])
        {
            vis[j]=1;
            j = ar[j].sec;
            cycle++;
        }
        ans+=(cycle-1);
    }
    f(i,0,n) vis1[i]=0;
    int ans1=0,cycle1;
    f(i,0,n)
    {
        if((vis1[i])||(ar1[i].sec==i))
            continue;
        cycle1=0;
        int j=i;
        while(!vis1[j])
        {
            vis1[j]=1;
            j = ar1[j].sec;
            cycle1++;
        }
        ans1+=(cycle1-1);
    }
    printf("%d\n",min(ans,ans1));   
    return 0;
}
