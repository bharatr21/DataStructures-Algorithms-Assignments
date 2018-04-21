#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int min(int a, int b) 
{
    return (a<b?a:b);
}
int max(int a, int b) {
    return (a>b?a:b);
}

int findMax(int A[], int n, int m) {
  int M[16][16] = {0};
  int cum[16] = {0};
  for (int i = 1; i <= n; i++)
    cum[i] = cum[i-1] + A[i-1];
 
  for (int i = 1; i <= n; i++)
    M[i][1] = cum[i];
  for (int i = 1; i <= m; i++)
    M[1][i] = A[0];
  for (int i = 2; i <= m; i++) {
    for (int j = 2; j <= n; j++) {
      int best = 999999;
      for (int p = 1; p <= j; p++) {
        best = min(best, max(M[p][i-1], cum[j]-cum[p]));
      }
      M[j][i] = best;
    }
  }
  return M[n][m];
}

int main()
{
    int i,n,m;
    scanf("%d%d",&n,&m);
    int A[n];
    f(i,0,n) scanf("%d",&A[i]);
    printf("%d\n",findMax(A,n,m));
    return 0;
}