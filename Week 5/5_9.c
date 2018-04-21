#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	int max=-99;
	f(i,0,n) 
	{ 
		scanf("%d",&a[i]); 
		if(max<a[i]) 
		{
			max=a[i];
		}
	}
	int fre[max+1];
	f(i,0,max+1) fre[i]=0;
	f(i,0,n) fre[a[i]]++;
	int fl=0;
	f(i,0,n)
	{
		if(fre[a[i]]&1) { fl=1; break; }
	}
	if(fl) printf("Vishal\n");
	else printf("Tanmay\n");
	return 0;
}
