#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int cmp(const void* a, const void* b)
{
	return (*(int*) a - *(int*) b);
}
int dcmp(const void* a, const void* b)
{
	return (*(int*) b - *(int*) a);
}

int sorter(int a[], int n)
{
	int b[n], c[n];
	int i,j=0,k=0;
	for(i=0;i<n;i+=2)
		b[j++] = a[i];
	for(i=1;i<n;i+=2)
		c[k++] = a[i];
	qsort(b,j,sizeof(b[0]),cmp);
	qsort(c,k,sizeof(c[0]),dcmp);
	f(i,0,j) a[i] = b[i];
	f(i,j,n) a[i] = c[i-j];
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	f(i,0,n) scanf("%d",&a[i]);
	sorter(a,n);
	f(i,0,n) printf("%d ",a[i]);
	printf("\n");
	return 0;
}
