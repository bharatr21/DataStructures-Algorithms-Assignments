#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)

struct point
{
	int x, y;
};

typedef struct point point;

float min(float x, float y) {return (x < y)?x:y; }

int cmpx(const void* a, const void* b)
{
	return ( (*(point*)a).x - (*(point*)b).x );
}

int cmpy(const void* a, const void* b)
{
	return ( (*(point*)a).y - (*(point*)b).y );
}

float dist(point p1, point p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) );
}

void search(point p[], int n, point ans[])
{
	float min = 999999.0;
	int idx1 = 0, idx2 = 0;
	f(i,0,n)
	{
		f(j,i+1,n)
		{
			if(dist(p[i], p[j]) < min) 
			{
				min = dist(p[i], p[j]);
				idx1 = i;
				idx2 = j;
			}
		}
	}
	ans[0] = p[idx1];
	ans[1] = p[idx2];
}

void stripclosest(point strip[], int size, float d, point ans[])
{
	float min = d;
	int idx1 = 0, idx2 = 0, j;
	f(i,0,size)
	{
		for(j=i+1;j < size && (strip[j].y - strip[i].y) < min; j++)
		{
			if(dist(strip[i], strip[j]) < min)
			{
				min = dist(strip[i], strip[j]);
				idx1 = i;
				idx2 = j;
			}
		}
	}
	ans[0] = strip[idx1];
	ans[1] = strip[idx2];
}

void closest(point px[], point py[], int n, point ans[])
{
	if(n <= 1) return;
	point ans1[2];
	if(n <= 3)
		search(px, n, ans);
	int mid = n/2;
	point midpt = px[mid];
	point pyl[mid+1], pyr[n-mid-1];
	int li=0, ri=0;
	f(i,0,n)	
	{
		if(py[i].x <= midpt.x)
			pyl[li++] = py[i];
		else
			pyr[ri++] = py[i];
	}
	closest(px, pyl, mid, ans);
	ans1[0] = ans[0];
	ans1[1] = ans[1];
	closest(px, pyr, n-mid, ans);
	ans = ( dist(ans1[0], ans1[1]) < dist(ans[0], ans[1]) ) ? ans1: ans;
	point strip[n];
	int j = 0;
	f(i,0,n)
	{
		if(abs(py[i].x - midpt.x) < dist(ans[0], ans[1]))
		{
			strip[j] = py[i]; 
			j++;
		}
	}
	float d = dist(ans[0], ans[1]);
	stripclosest(strip, j, d, ans1);
	ans = (d < dist(ans1[0], ans1[1]) ) ? ans: ans1;
}
 
int main()
{
	int n;
	scanf("%d",&n);
	point p[n], px[n], py[n], ans[2];
	f(i,0,n)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		px[i] = p[i];
		py[i] = p[i];
	}
	qsort(px, n, sizeof(px[0]), cmpx);
	qsort(py, n, sizeof(py[0]), cmpy);
	closest(px, py, n, ans);
	printf("%d %d\n",ans[0].x, ans[0].y);
	printf("%d %d\n",ans[1].x, ans[1].y);
	return 0;
}
