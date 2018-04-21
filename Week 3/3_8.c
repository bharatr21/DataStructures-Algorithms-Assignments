#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int cmp(const void* c, const void* d)
{
	return (*(int*)c - *(int*)d);
}

int main()
{
	int n,m,i,j,k;
	scanf("%d%d",&m,&n);
	int a[n], ans[n], temp[m];
	float med;
	f(i,0,n) scanf("%d",&a[i]);
	f(i,0,m) ans[i]=-1;
	f(i,m,n) ans[i]=0;
	f(i,0,n) printf("%d ",a[i]);
	printf("\n");
	f(j,0,n-m)
	{
		int idx=0;
		f(i,j,j+m)
		{
			temp[idx++] = a[i];
		}
		printf("Iteration %d: ",j);
		f(k,0,idx) printf("%d ",temp[k]);
		printf("\n");
		qsort(temp,m, sizeof(int),cmp);
		printf("Sorted window: ");
		f(k,0,idx) printf("%d ",temp[k]);
		printf("\n");
		if(idx&1)
			med=temp[idx/2];
		else
			med=(temp[(idx/2)-1]+temp[(idx/2)])/2.0;
		printf("Median is %f\n",med );
		printf("Compared with: %d\n", a[j+m]);
		if(a[j+m]>3*med)
			ans[j+m]=1;
		else
			ans[j+m]=0;
	}
	f(i,0,n) printf("%d ",ans[i] );
	printf("\n");
	return 0;
}