#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

int ok(int n, int a[][n], int r, int c)
{
	int i,j;
	f(i,0,c)
	{
		if(a[r][i]) return 0;
	}
	for(i=r, j=c; i>=0 && j>=0; i--, j--)
	{
		if(a[i][j]) return 0;
	}
	for(i=r, j=c; i < n && j >= 0; i++, j--)
	{
		if(a[i][j]) return 0;
	}
	return 1;
}

int solveq(int n, int a[][n], int col)
{
	if(col >= n) return 1;
	f(i,0,n)
	{
		if(ok(n, a, i, col))
		{
			a[i][col] = 1;
			if(solveq(n, a, col + 1)) 
				return 1;
			a[i][col] = 0; //Backtracking Step
		}
	}
	return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n][n];
	memset(a, 0, sizeof(a[0][0])*n*n);
	if(solveq(n, a, 0))
	{
		f(i,0,n)
		{
			f(j,0,n)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("Solution does not exist\n");
	return 0;
}
