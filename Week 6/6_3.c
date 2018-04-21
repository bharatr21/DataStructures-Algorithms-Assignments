#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

int s[10000];
int tp=-1; 

void push(int ele){
	s[++tp] = ele;
}

int empty() {return (tp==-1); }

int pop(){ return (empty()?-1:s[tp--]); }

int top() {return (empty()?-1:s[tp]); }

int main()
{
	int fl=0;
	int a[11][11];
	f(i,1,11)
	{
		f(j,1,11)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int ct=0, i=1, j=1;
	while(i!=10 || j!=10)
	{
		if(j+1<=10 && (a[i][j+1]==1))
		{
			++a[i][j+1];
			push(1);
			j++;
		}
		else if(i+1<=10 && (a[i+1][j]==1))
		{
			++a[i+1][j];
			push(2);
			i++;
		}
		else if(j-1>=1 && (a[i][j-1]==1))
		{
			++a[i][j-1];
			push(3);
			j--;
		}
		else if(i-1>=1 && (a[i-1][j]==1))
		{
			++a[i-1][j];
			push(4);
			i--;
		}
		else
		{
			if(empty()) break;
			int ele = pop();
			if(ele==1) { ++a[i][j-1]; j--; }
			if(ele==2) { ++a[i-1][j]; i--; }
			if(ele==3) { ++a[i][j+1]; j++; }
			if(ele==4) { ++a[i+1][j]; i++; }
		}
	}
	if(empty())
	{
		printf("\nNo paths available\n");
		fl=1;
	}
	printf("\nTries taken\n");
	printf("\n");
	f(i,1,11)
	{
		f(j,1,11)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	char path[100];
	int idx=0;
	while(tp!=-1)
	{
		int ele = pop();
		if(ele==1) {path[idx++]='R';}
		if(ele==2) {path[idx++]='D';}
		if(ele==3) {path[idx++]='L';}
		if(ele==4) {path[idx++]='U';}
	}
	idx--;
	if(fl) return 0;
	printf("\nFinal path\n");
	fd(i,idx,0) printf("%c", path[i]);
	return 0;
}
