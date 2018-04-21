#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define MAX 999999

typedef struct 
{
    int color;
    int cost;
}pair;
 

void calc(int a[], int n)
{
    pair dp[n][n];
    //dp[i][j] represents min cost for the subarray [i..j] and has the resultant color
    f(i,0,n)
    {
        dp[i][i].color = a[i];
        dp[i][i].cost = 0;
    }
    f(l,2,n+1)
    {
        f(i,0,n-l+1)
        {
            int j = i + l - 1;
            dp[i][j].cost = MAX;
            f(k,0,l-1)
            {
                if(dp[i][j].cost > (dp[i][i+k].cost + dp[i+k+1][j].cost + dp[i][i+k].color * dp[i+k+1][j].color))
                {
                    dp[i][j].cost = dp[i][i+k].cost + dp[i+k+1][j].cost + dp[i][i+k].color * dp[i+k+1][j].color;
                    dp[i][j].color = (dp[i][i+k].color + dp[i+k+1][j].color) % 100;
                }
            }
        }
    }
    printf("%d\n",dp[0][n-1].cost);
}

int main()
{
    // int t;
    // scanf("%d",&t);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        // scanf("%d",&n);
        int a[n];
        f(i,0,n) scanf("%d",&a[i]);
        calc(a, n);
    }
    return 0;
}
