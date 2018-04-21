#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

int max(int x, int y) {return (x>y?x:y); }
int min(int x, int y) {return (x<y?x:y); }

int median(int a[], int b[], int n)
{
	int m1, m2;
	if(n <= 0) return -1;
	if(n == 1) return (a[0]+b[0])/2;
	if(n == 2) return (max(a[0], b[0]) + min(a[1], b[1]))/2;
	if(n%2)
	{
		m1 = a[n/2];
		m2 = b[n/2];
	}
	else
	{
		m1 = (a[n/2]+a[n/2-1])/2;
		m2 = (b[n/2]+b[n/2-1])/2;
	}
	if(m1 == m2) return m1;
	if(m1 < m2)
	{
		if(n%2)
			return median(a + n/2, b, n - n/2);
		else
			return median(a + n/2 - 1, b, n - n/2 + 1);
	}
	if(n%2)
			return median(b + n/2, a, n - n/2);
		else
			return median(b + n/2 - 1, a, n - n/2 + 1);
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n], b[n];
	f(i,0,n) scanf("%d",&a[i]);
	f(i,0,n) scanf("%d",&b[i]);
	printf("%d\n",median(a, b, n));
	return 0;
}
