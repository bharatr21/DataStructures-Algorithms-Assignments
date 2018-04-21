#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define MAX 999999

int main()
{
	int n, i, j, t, min, temp;
	min = MAX;
	scanf("%d",&n);
	int a[n];
	f(i,0,n) 
	{
		scanf("%d",&a[i]);
		if(min > a[i])
			min = a[i];
	}
	int min_r = MAX;
	f(t,0,5)
	{
		int r = 0;
		f(i,0,n)
		{
			int diff = a[i] - (min - t);
			r += diff/5;
			diff = diff % 5;
			r += diff/3;
			diff = diff % 3;
			r += diff;
		}
		if(r < min_r) min_r = r;
	}
	printf("%d\n",min_r);
	return 0;
}
