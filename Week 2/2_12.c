#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int first(int x,int l,int h,int* a,int n)
{
	while(h>=l)
	{
		int m = l + (h-l)/2;
		if((m == 0|| a[m-1] < x) && (a[m] == x))
			return m;
		else if(x > a[m])
			l = m + 1;
		else
			h = m - 1;
	}
	return -1;
}

int last(int x,int l,int h,int* a,int n)
{
	while(h>=l)
	{
		int m = l + (h-l)/2;
		if(( (m == n-1) || (a[m+1] > x) ) && (a[m] == x))
			return m;
		else if(x < a[m])
			h = m - 1;
		else
			l = m + 1;
	}
	return -1;
}

int main()
{
	int n,x,i;
	scanf("%d%d",&n,&x);
	int* a = malloc(n*sizeof(int));
	f(i,0,n) scanf("%d",&a[i]);
	int j,k;
	j = first(x,0,n-1,a,n);
	if(j==-1) {
		printf("Element not present in array\n");
		return -1;
	}
	else{
		k = last(x,j,n-1,a,n);
		printf("%d\n",k-j+1);	
	}
	return 0;
}