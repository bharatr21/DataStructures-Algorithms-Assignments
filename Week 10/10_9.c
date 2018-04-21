#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)

int findcand(int a[], int n)
{
	int maj_idx = 0, cnt = 1;
	f(i,1,n)
	{
		if(a[maj_idx] == a[i])
			cnt++;
		else
			cnt--;
		if(!cnt)
		{
			maj_idx = i;
			cnt = 1;
		}
	}
	return a[maj_idx];
}

int ismajority(int a[], int n, int cand)
{
	int cnt = 0;
	f(i,0,n)
		if(a[i] == cand) cnt++;
	return (cnt > n/2);
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	f(i,0,n) scanf("%d",&a[i]);
	int cand = findcand(a, n);
	if(ismajority(a, n, cand))
		printf("%d\n",cand);
	else
		printf("NONE\n");
	return 0;
}	
