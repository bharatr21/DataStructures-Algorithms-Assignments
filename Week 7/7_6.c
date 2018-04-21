#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)

int lo2(int x)
{
	int ans = 0;
	while(x>>=1) ans++;
	return ans;
}

int parent(int i) {return (i-1)/2; }
int left(int i) { return (2*i+1); }
int right(int i) { return (2*i+2); }

int find(int A[], int i, int tot)
{
	int j;
	f(j,0,tot)
	{
		if(A[j] == i)
			return j;
	}
	return -1;
}

void findminmax(int A[], int idx, int* min, int* max, int hd, int tot)
{
	if(idx <= tot) {
		if(A[idx] == -1) return;
		if(hd < *min) *min = hd;
		else if(hd > *max) *max = hd;
		findminmax(A, left(idx), min, max, hd-1, tot);
		findminmax(A, right(idx), min, max, hd+1, tot);
	}
}

void printline(int A[], int idx, int lno, int hd, int tot)
{
	if(idx <= tot) {
		if(A[idx] == -1) return;
		if(hd == lno) printf("%d ",A[idx]);
		printline(A, left(idx), lno, hd-1, tot);
		printline(A, right(idx), lno, hd+1, tot);
	}
}

void verticaltrav(int A[], int idx, int tot)
{
	if(idx <= tot) {
		int min = 0, max = 0;
		findminmax(A, idx, &min, &max, 0, tot);
		int lno;
		f(lno, min, max+1)
		{
			printline(A, idx, lno, 0, tot);
			printf("\n");
		}
	}
}

int main()
{
	int n,i,j,idx;
	char ch;
	scanf("%d %d",&n,&j);
	int tot = (2<<lo2(n))-1;
	int A[2*tot+3];
	f(i,0,2*n+3) A[i]=-1;
	A[0] = j;
	printf("\n");
	while(n--)
	{
		scanf("%d %d %c",&i,&j,&ch);
		idx = i-1;
		if(idx == -1) {printf("Given value not present in tree and children cannot be inserted\n"); return -1;}
		else
		{
			if(ch == 'L')
			{
				A[left(idx)] = j;
			}
			else if(ch == 'R')
			{
				A[right(idx)] = j;
			} 
		}
	}
	verticaltrav(A, 0, tot);
	return 0;
}
