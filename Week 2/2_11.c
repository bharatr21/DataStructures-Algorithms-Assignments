#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

int main()
{
    ll el[2],ind[2];
    el[0] = -1; el[1]=-1;
    ind[0] = -1; ind[1]=-1;
    ll n, i;
    scanf("%lld\n",&n);
    int* a = malloc(n*sizeof(int));
    f(i,0,n) scanf("%d",&a[i]);
    fd(i,n-1,0)
    {
        if(a[i] < a[i-1])
        {
            el[0]=a[i];
            ind[0]=i;
            int j = i-1;
            while(j >= 0 && a[i] < a[j])
                j--;
            el[1] = a[j+1];
            ind[1] = j+1;
        }
    }
    printf("%lld %lld\n %lld %lld\n",el[0],el[1],ind[0],ind[1]);
    return 0;
}