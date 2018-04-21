#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define MAX 100005

int minkey(int* key, int* mset, int n)
{
	int min=MAX, idx, v;
	f(v,0,n) {
		if((!mset[v])&&(key[v]<min)) {
			min = key[v]; idx=v;
		}
	}
	return idx;
}

int ans(int n, int* parent, int graph[n][n]) {
	int sum=0, i;
	f(i,0,n)
		sum+=graph[i][parent[i]];
	return sum;
} 
int prim(int n, int graph[n][n])
{
	int parent[n];
	int key[n];
	int mset[n];
	int i, count, v;
	f(i,0,n){
		key[i] = MAX;
		mset[i] = 0;
	}
	key[0] = 0;
	parent[0] = -1;
	f(count, 0, n-1) {
		int u = minkey(key, mset, n);
		mset[u] = 1;
		f(v,0,n) {
			if( (graph[u][v]) && (!mset[v]) && (graph[u][v] < key[v]) ) {
				parent[v] = u; key[v] = graph[u][v];
			}
		}
	}
	int weight = ans(n, parent, graph);
	return weight;
}

int main()
{
	int n, m, i, j, u;
	int graph[n][n];
	scanf("%d%d",&n,&m);
	f(i,0,n)
	{
		f(j,0,n)
		{
			graph[i][j] = 0;
		}
	}
	while(m--)
	{
		scanf("%d %d %d", &i, &j, &u);
		printf("%d %d %d",i,j,u);
		graph[i][j] = u;
		graph[j][i] = u;
	}
	printf("\n");
	f(i,0,n)
	{
		f(j,0,n)
		{
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", prim(n, graph));
	return 0;
}
