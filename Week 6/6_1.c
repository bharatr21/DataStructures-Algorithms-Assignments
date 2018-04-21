#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)

int stack[10001];
int tp=-1;

void push(int n)
{
	stack[++tp] = n;
}

void pop() {tp--;}

int top() { return stack[tp]; }

int empty() { return (tp==-1); }

ll getmaxarea(ll* h, int n) {
	ll maxarea=0;
	int tp;
	ll areatop;
	int i=0;
	while(i < n) {
		if(empty()||(h[top()] <= h[i]))
			push(i++);
		else {
			tp = top();
			pop();
			areatop = h[tp]*(empty()?i:i-top()-1);
			if(maxarea < areatop)
				maxarea = areatop;
		}
	}	
	while(!empty()) {
		tp = top();
		pop();
		areatop = h[tp]*(empty()?i:i-top()-1);
		if(maxarea < areatop)
			maxarea = areatop;
	}
	return maxarea;
}

int main()
{
	int n;
	scanf("%d", &n);
	ll h[n];
	f(i,0,n) scanf("%lld",&h[i]);
	printf("%lld\n",getmaxarea(h, n));
	return 0;
}
