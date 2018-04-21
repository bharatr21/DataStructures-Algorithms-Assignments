#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)

int cmp(const void* a, const void* b)
{
	return ( *(int*)a - *(int*)b );
}

int llgp(int a[], int n)
{
	if(n < 2) return n;
	if(n == 2) return ( a[1]%a[0] == 0);
	int i, j, k;
	int lgp[n][n];
	int res = 1;
	f(i,0,n)
	{
		if(a[i] && a[n-1]%a[i] == 0)
			lgp[i][n-1] = 2;
		else
			lgp[i][n-1] = 1;
	}
	fd(j, n-2, 1)
	{
		int i = j-1, k = j+1;
		while(i >= 0 && k <= n-1)
		{
			if(a[i]*a[k] < a[j]*a[j])
				k++;
			else if(a[i]*a[k] > a[j]*a[j])
			{
				if(a[j]%a[i])
					lgp[i][j] = 1;
				else
					lgp[i][j] = 2;
				i--;
			}
			else
			{
				lgp[i][j] = lgp[j][k] + 1;
				if(lgp[i][j] > res)
					res = lgp[i][j];
				k++;
				i--;
			}
		}
		while(i >= 0)
		{
			if(a[j]%a[i])
				lgp[i][j] = 1;
			else
				lgp[i][j] = 2;
			i--;
		}
	}
	return res;
}

int main()
{
	int n, i;
	scanf("%d",&n);
	int a[n];
	f(i,0,n) scanf("%d",&a[i]);
	qsort(a, n, sizeof(a[0]), cmp);
	printf("%d\n", llgp(a, n));
	return 0;
}
