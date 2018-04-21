#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

void rev(int* a,int i, int n)
{
	if(i>=n) return; 
	int j=0, k=i;
	char temp;
	while(j<k)
	{
		temp = a[j];
		a[j] = a[k];
		a[k] = temp;
		j++;
		k--;
	}
}

int findmax(int* a, int n)
{
	int ma=a[0],idx=0,i;
	f(i,0,n) {
		if(ma<a[i]) {
			ma=a[i];
			idx=i;
		}
	}
	return idx;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int j=n;
	int a[n];
	f(i,0,n) scanf("%d",&a[i]);
	fd(j,n,1)
	{
		int idx = findmax(a,j);
		if(idx!=j-1)
		{
			rev(a,idx,n);
			rev(a,j-1,n);
		} 
	}
	f(i,0,n) printf("%d ",a[i]);
	printf("\n");
	return 0;
}
