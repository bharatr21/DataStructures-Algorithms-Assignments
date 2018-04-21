#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define MAX 100005

int minkey(int n, int key[], int mst[]) {
	int min = 100001, idx;
	f(i,0,n) {
		if(mst[i] && key[i] < min) {
			min = key[i]; idx = i;
		}
	}
	return idx; 
}

int prim(int n, int graph[n][n]) {
	int par[n];
	int key[n];
	int mst[n];
	int sum = 0;
	int u;
	f(i,0,n) {
		key[i] = 100001; mst[i] = 0;
	}
	key[0] = 0;
	par[0] = -1;
	f(ct,0,n-1) {
		u = minkey(n, key, mst);
		mst[u] = 1;
		f(i,0,n) {
			if(graph[u][i] && !mst[i] && (graph[u][i] < key[i]) ) {
				par[i] = u; key[i] = graph[u][i];
			}
			if(key[i] > graph[i][u]) key[i] = graph[i][u];
		}
	}
	f(i,0,n) printf("%d ",graph[i][par[i]]);
	printf("\n");
	f(i,0,n) sum+=graph[i][par[i]];
	return sum;
}

int main()
{
	int n,m,x,y,z;
	scanf("%d%d",&n,&m);
	int graph[n][n], key[n], sum=0, mini, idx;
	f(i,0,n) {
		f(j,0,n) {
			graph[i][j] = 0;
		}
	}
	f(i,0,m) {
		scanf("%d %d %d",&x,&y,&z);
		graph[x-1][y-1] = z;
		graph[y-1][x-1] = z;
	}
	f(i,0,n) {
		f(j,0,n) {
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	printf("%d\n",prim(n, graph));
	return 0;
}
