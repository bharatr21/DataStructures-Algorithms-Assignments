#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

int find(int* parent, int x)
{
	if(parent[x] == x)
		return x;
	else return find(parent, parent[x]);
}

void unions(int* parent, int x, int y)
{
	int a, b;
	a = find(parent, x);
	b = find(parent, y);
	parent[b] = a;
}

int main()
{
	int n, e, j, k, ct = 0;
	scanf("%d%d",&n,&e);
	int parent[n+1], vis[n+1];
	f(i,1,n+1) { vis[i] = 0; parent[i] = i; }
	f(i,0,e)
	{
		scanf("%d%d",&j,&k);
		unions(parent, j, k);
	}
	
	printf("\nConnected Components\n");
	f(i,1,n+1)
	{
		int flag = 0;
		f(j,1,n+1)
		{
			if(i == find(parent, j))
			{
				printf("%lld ",j);
				flag = 1;
			}
		}
		if(flag) printf("\n");
	}

	printf("\nCount: ");
	f(i,1,n+1)
	{
		j = find(parent, i);
		if(!vis[j])
		{
			ct++;
			vis[j] = 1;
		}
	}
	printf("%d\n",ct);
	return 0;
}