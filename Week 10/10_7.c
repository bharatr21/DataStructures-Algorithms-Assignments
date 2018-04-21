#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
int bin[100000][32]; //Binary representaion of n
int pre[100000][32]; //Prefix Sum Array

void init(int n)
{
	f(i,0,n)
	{
		f(j,0,32)
		{
			bin[i][j] = 0;
		}
	}
}

void conv(int a[], int n)
{
	f(i,0,n)
	{
		int j = 0;
		while(a[i])
		{
			bin[i][j] = a[i]&1; //a[i]%2
			a[i]>>=1; //a[i]/2
			j++;
		}
	}
}

void presum(int n)
{
	f(i,0,32)
	{
		f(j,0,n)
		{
			if(!j)
			{
				pre[j][i] = bin[j][i];
			}
			else
			{
				pre[j][i] = bin[j][i] + pre[j-1][i];
			}
		}
	}
}

int main()
{
	int n,q,l,r;
	int a[100000], b[100000], ans, ct1, ct0;
	scanf("%d%d",&n,&q);
	f(i,0,n) { scanf("%d",&a[i]); b[i] = a[i]; }
	init(n);
	conv(b, n);
	presum(n);
	while(q--)
	{
		ans = 0;
		scanf("%d%d",&l,&r);
		f(i,0,31)
		{
			if(bin[l-1][i])
			{
				ct1 = pre[r-1][i] - pre[l-1][i] + 1;
			}
			else
			{
				ct1 = pre[r-1][i] - pre[l-1][i];
			}
			ct0 = r - l + 1 - ct1;
			if(ct1 < ct0)
			{
				ans += (1<<i); //ans = ans + 2^i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}