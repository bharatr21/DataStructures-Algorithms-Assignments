#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

int max(int a, int b)
{
	return ((a>b)?a:b);
}

int min(int a, int b)
{
	return ((a<b)?a:b);
}

int main()
{
	int p,q,r,i,j,k,fi,fj,fk;
	scanf("%d %d %d",&p,&q,&r);
	int diff=999999,minimum,maximum;
	int* a = malloc(p*sizeof(int));
	int* b = malloc(q*sizeof(int));
	int* c = malloc(r*sizeof(int));
	f(i,0,p) scanf("%d",&a[i]);
	f(j,0,q) scanf("%d",&b[j]);
	f(k,0,r) scanf("%d",&c[k]);
	i=j=k=0;
	while(i<p&&j<q&&k<r)
	{
		minimum = min(a[i],min(b[j],c[k]));
		maximum = max(a[i],max(b[j],c[k]));
		if(maximum-minimum < diff)
		{
			fi=i; fj=j; fk=k;
			diff = maximum-minimum;
		}
		if(diff == 0) break;
		if(minimum == a[i]) i++;
		else if(minimum == b[j]) j++;
		else k++;
	}
	printf("%d %d %d\n",a[fi],b[fj],c[fk]);
	return 0;
}