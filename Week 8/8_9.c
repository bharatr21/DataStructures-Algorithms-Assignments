#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

int stack[1000];
int tp=-1;

int empty() {return (tp==-1); }
void push(int key) {stack[++tp] = key; }
int top() {return (empty()?-1:stack[tp]); }
void pop() {tp--;}

void dfs(int n, int g[][n+1], int* vis, int i)
{
	vis[i] = 1;
	push(i);
	while(!empty())
	{
		int p = top();
		pop();
		f(j,1,n+1)
		{
			if(g[p][j] && !vis[j]) 
			{
				vis[j] = 1;
				push(j);
			}
		}
	}
}

int main()
{
	int n, e, i, j;
	scanf("%d %d",&n,&e);	
	int g[n+1][n+1], vis[n+1];
	f(i,1,n+1)
	{
		vis[i] = 0;
		f(j,1,n+1)
		{
			g[i][j] = 0;
		}
	}
	int flag=1;
	int ct=0;
	while(e--)
	{
		scanf("%d %d",&i,&j);
		g[i][j] = 1;
		g[j][i] = 1;
	}
	while(flag)
	{
		flag=0;
		f(i,1,n+1)
		{
			if(!vis[i]) 
			{
				ct++;
				flag=1;
				dfs(n,g,vis,i);
			}
		}
	}
	printf("%d\n",ct);
	return 0;
}
