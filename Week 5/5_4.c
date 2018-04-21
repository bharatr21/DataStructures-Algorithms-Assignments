#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

int min(int x, int y) { return ((x<y)?x:y); }

int main()
{
	int m,n,i,rot,j;
	ll r;
	scanf("%d %d %lld",&m,&n,&r);
	int** a = malloc(m*sizeof(int*));
	f(i,0,m)
	{
		a[i] = malloc(n*sizeof(int));
	}
	f(i,0,m)
	{
		f(j,0,n)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int numrings = min(m,n)/2;
	int numrot,tmp;
	f(i,0,numrings)
	{
		numrot = r%(2*(m+n-4*i)-4);
		f(rot,0,numrot)
		{
			//Top row
			f(j,i,n-1-i)
			{
				tmp=a[i][j];
				a[i][j] = a[i][j+1];
				a[i][j+1] = tmp;

			}
			//Right column
			f(j,i,m-1-i)
			{
				tmp=a[j][n-1-i];
				a[j][n-1-i]=a[j+1][n-1-i];
				a[j+1][n-1-i]=tmp;
			}
			//Bottom row
			fd(j,n-1-i,i)
			{
				tmp=a[m-1-i][j];
				a[m-1-i][j]=a[m-1-i][j-1];
				a[m-1-i][j-1]=tmp;
			}
			//Left column
			fd(j,m-1-i,i+1)
			{
				tmp=a[j][i];
				a[j][i] = a[j-1][i];
				a[j-1][i] = tmp;
			}
		}
	}
	printf("\n-------------------------------------------------\n");
	f(i,0,m)
	{
		f(j,0,n)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	f(i,0,m)
	{
		free(a[i]);
	}
	free(a);
	return 0;
}
