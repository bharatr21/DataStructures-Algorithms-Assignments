#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

int lo2(int x)
{
	int ans=0;
	while(x>>=1) ans++;
	return ans;
}

struct node
{
	int key;
	struct node* left;
	struct node* right;
};

int left(int i) {return (2*i+1); }
int right(int i) {return (2*i+2); }
int parent(int i) {return (i-1)/2; }

typedef struct node node;

int count(int A[], int idx, int tot)
{
	if(idx >= tot) return 0;
	if(A[idx] == -1) return 0;
	else return (1 + count(A, left(idx), tot) + count(A, right(idx), tot) );
}

int isComplete(int A[], int idx, int nnodes)
{
	if(A[idx] == -1) return 1;
	if(idx >= nnodes) return 0;
	return ( isComplete(A,2*idx+1,nnodes) && isComplete(A, 2*idx+2, nnodes) );
}

int isHeap(int A[], int idx)
{
	if(A[left(idx)] == -1 && A[right(idx)] == -1)
		return 1;
	else {
		if( (A[idx] >= A[left(idx)]) && (A[idx] >= A[right(idx)]) ) {
			return ( (isHeap(A, right(idx)) ) && ( isHeap(A, left(idx))) );
		}
		else
			return 0;
	}
}

int checkHeap(int A[], int tot)
{
	int nnodes = count(A, 0, tot);
	int idx = 0;
	if( isHeap(A, 0) && isComplete(A, 0, nnodes) ) {
		return 1;
	}
	return 0;
}

int find(int A[], int i, int n)
{
	f(idx, 0, 2*n+3) {
		if(A[idx] == i) {
			return idx;
		}
	}
	return -1;
}

int main()
{
	int m,i,j,idx;
	char ch;
	scanf("%d %d",&m, &j);
	int tot=(1<<(lo2(m)+1))-1;
	int A[2*tot+3];
	f(i,0,2*tot+3) A[i]=-1;
	A[0] = j;
	while(m--)
	{
		scanf("%d %d %c",&i, &j, &ch);
		idx = find(A, i, tot);
		if(idx == -1) { printf("Unable to find node with this value\n"); printf("Difficult\n"); return 0; }
		else {
			if(ch == 'R')
			{
				A[right(idx)] = j;
			}
			else if(ch == 'L')
			{
				A[left(idx)] = j;
			}
		}
	}
	if(checkHeap(A, tot))
	{
		printf("Easy\n");
	}
	else printf("Difficult\n");
	return 0;
}
