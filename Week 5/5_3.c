#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int max=-999;

int findmax(int r, int c, int **a)
{
	int maxidx=0,i;
	f(i,0,r)
	{
		if(max < a[i][c])
		{
			max=a[i][c];
			maxidx=i;
		}
	}
	return maxidx;	
}

int findpeak(int r, int c, int mid, int **a)
{
	int maxidx = findmax(r,mid,a);
	if(mid==0||mid==c-1) return max;
	else if(max>=a[maxidx][mid-1]&&max>=a[maxidx][mid+1]) return max;
	else
	{
		if(max<a[maxidx][mid-1]) return findpeak(r,c,mid-mid/2,a );
		else return findpeak(r,c,mid+mid/2,a);
	}
}

int main()
{
	int i,j,r,c;
	scanf("%d %d",&r,&c);
	int **a = malloc(sizeof(int*) * r);
	f(i,0,r) {
		a[i] = malloc(sizeof(int) * c);
	}
	f(i,0,r)
	{
		f(j,0,c)
		{
			scanf("%d",&a[i][j]);
		}
	}
	f(i,0,r)
	{
		f(j,0,c)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("%d\n",findpeak(r,c,c/2,a));
	f (i,0,r) 
	{
		free(a[i]);
	}
	free(a);
	return 0;
}
