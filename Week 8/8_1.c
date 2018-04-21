#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

struct point
{
	int x,y;
};

typedef struct point point;

point p0;

point stack[1000];
int tp=-1;
void push(point key) { stack[++tp] = key; }
int empty() { return (tp==-1); }
point top() { return stack[tp]; }
void pop() {tp--;}
point nexttop() 
{
	point p = top();
	pop();
	point res = top();
	push(p);
	return res;
}

void swap(point *p1, point *p2)
{
	point temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int dist(point p1, point p2)
{
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

int dir(point p, point q, point r)
{
	int val = (r.x - q.x) * (q.y - p.y) - (q.x - p.x) * (r.y - q.y);
	if(!val) return 0;
	return (val > 0)? 1: 2;  
}

int cmp(const void* v1, const void* v2)
{
	point* p1 = (point*)v1;
	point* p2 = (point*)v2;
	int d = dir(p0, *p1, *p2);
	if(!d)
		return (dist(p0, *p2) >= dist(p0, *p1)) ? -1: 1;
	else
		return (d==2)?-1: 1;
}

int convex(point points[], int n, point ans[])
{
	int ymin = points[0].y, min=0;
	f(i,1,n)
	{
		int y = points[i].y;
		if((y < ymin)||(ymin == y && points[i].x < points[min].x)){
			ymin = points[i].y; min=i;
		}
	}
	swap(&points[0], &points[min]);
	p0 = points[0];
	qsort(&points[1], n-1, sizeof(point), cmp);
	int m = 1;
	f(i,1,n)
	{
		while(i < n-1 && dir(p0,points[i], points[i+1]) == 0)
			i++;
		points[m] = points[i];
		m++;
	}

	if(m < 3) return -1;
	push(points[0]);
	push(points[1]);
	push(points[2]);
	f(i,3,m)
	{
		while(dir(nexttop(), top(), points[i]) != 2)
			pop();
		push(points[i]);
	}
	int k = 0;
	while(!empty())
	{
		point p = top();
		ans[k++] = p;
		pop();
	}
	return k;
}

int main()
{
	int n;
	scanf("%d",&n);
	point points[n], ans[n];
	f(i,0,n)
	{
		scanf("%d %d",&points[i].x, &points[i].y);
	}
	int k = convex(points, n, ans);
	printf("\n");
	printf("%d\n",k);
	f(i,0,k)
	{
		printf("%d %d\n",ans[i].x, ans[i].y);
	}
	return 0;
}
