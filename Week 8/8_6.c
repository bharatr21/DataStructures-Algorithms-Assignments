#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define left(i) (((i)<<1) + 1)
#define right(i) ((i)<<1) + (1<<1)
#define parent(i) ((i)-1)>>1

int find(int parent[], int i)
{
	if(parent[i] == -1)
		return i;
	else return find(parent, parent[i]);
}

void unions(int parent[], int x, int y)
{
	int xs = find(parent, x);
	int ys = find(parent, y);
	parent[xs] = ys;
}

int isCycle(int n, int g[][n])
{
	int parent[n], vis[n][n];
	f(i,0,n) parent[i]=-1;
	f(i,0,n)
	{
		f(j,0,n)
		{
			vis[i][j] = 0;
		}
	}

	f(i,0,n)
	{
		f(j,0,n)
		{
			if(!vis[i][j] && g[i][j])
			{
				vis[i][j] = 1;
				int x = find(parent, i);
				int y = find(parent, j);
				if(x == y) return 1;
				unions(parent, x, y);
			}
		}
	}
	return 0;
}

int isBST(int* A, int idx)
{
	static int prev = -99;
	if(!isBST(A, left(idx)))
		return 0;
	if((prev != -99) && (prev < A[idx]))
		return 0;
	prev = A[idx];
	return isBST(A, right(idx));
}

int main()
{
	int n,e,i,j;
	int g[n][n];
	f(i,0,n)
	{
		f(j,0,n)
		{
			g[i][j] = 0;
		}
	}
	while(e--)
	{
		scanf("%d %d",&i,&j);
		g[i][j] = 1;
		g[j][i] = 1;
	}
	if(!isCycle(n, g))
	{
		printf("Yes, it is a Binary Tree\n");
		//Convert to an array A having complete binary tree representation
		if(isBST(A, 0))
		{
			printf("Yes, it is a Binary Search Tree\n");
		}
	}
	else
		printf("Graph with Cycle\n");
	return 0;
}
