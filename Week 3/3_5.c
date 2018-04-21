#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

typedef struct {
ll val;
ll ind;
} s;

s ss[51];
int cmp(const void* a, const void* b)
{
	if(((s*)a)->val < ((s*)b)->val)
	{
		return 0;
	}
	else if(((s*)a)->val == ((s*)b)->val)
	{
		if(((s*)a)->ind < ((s*)b)->ind)
			return 0;
		else
			return 1;
	}
	else
		return 1;
}

ll getNum(ll prev_div_val, ll which_th_num, ll bars) {
	return (which_th_num / bars) + prev_div_val;
}

int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);
	f(i,0,n)
	{	
		scanf("%lld",&ss[i].val);
		ss[i].ind = 1;
	}
	f(i,n,2*n)
	{	
		scanf("%lld",&ss[i].val);
		ss[i].ind = 0;
	}
	qsort(ss, 2*n, sizeof(s), cmp);
/*	f(i,0,2*n)
	{
		printf("%lld %lld\n",ss[i].val,ss[i].ind);
	}*/
	ll bars = 0, cnt = 0;
	i = 0;
	ll prev_div_val = 0, div_val = 0; // should be initialized but to anything
	while (1) {
		div_val = ss[i].val;
		ll cnt_change = bars * (div_val - prev_div_val + 1); 
		if (cnt + cnt_change >= m + 1) {
			printf("%lld\n",getNum(prev_div_val, m + 1 - cnt, bars));
			break;
		}

		ll bars_change = 0;
		// handle intervals that end at ss[i].val
		while (i < 2 * n && ss[i].ind == 0 && ss[i].val == div_val) {
			--bars_change;
			++i;
		}
		bars += bars_change;
		bars_change = 0;
		cnt += cnt_change;
		prev_div_val = div_val;
		// handle intervals that begin at ss[i].val
		while (i < 2 * n && ss[i].ind == 1 && ss[i].val == div_val) {
			++bars_change;
			++i;
		}
		bars += bars_change;
	}
	return 0;
}
