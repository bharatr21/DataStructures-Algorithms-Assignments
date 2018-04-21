#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

int main()
{
	int n, od = 0, mididx=-1;
	scanf("%d",&n);
	char str[n]; 
	int fre[26]={}, filledidx[26]={};
	getchar();
	f(i,0,n)
	{
		scanf("%c",&str[i]);
		fre[str[i]-'a']++;
	}
	int** ans = malloc(26*sizeof(int*));
	f(i,0,26)
	{
		ans[i] = malloc( (fre[i] + 1)*sizeof(int));
	}
	// f(i,0,26) {printf("%d ",fre[i]); } printf("\n");


	f(i,0,n)
	{
		ans[str[i]-'a'][filledidx[str[i]-'a']] = i + 1;
		filledidx[str[i]-'a']++;
	}

	// f(i,0,26)
	// {
	// 	f(j,0,filledidx[i])
	// 	{
	// 		printf("%d ",ans[i][j]);
	// 	}
	// 	printf("\n");
	// }

	f(i,0,26)
	{
		if(fre[i]&1) od++;
	}

	if(od >= 2) { printf("-1\n"); return 0; }
	
	f(i,0,26)
	{
		if(fre[i]&1)
		{
			mididx = ans[i][filledidx[i]/2];
			break;
		}
	}
	f(i,0,26)
	{
		f(j,0,(filledidx[i])/2)
		{
			if(ans[i][j] != mididx)
				printf("%d ",ans[i][j]);
		}
	}
	if(mididx != -1) printf("%d ",mididx);
	fd(i,25,0)
	{
		f(j,(filledidx[i])/2, filledidx[i])
		{
			if(ans[i][j] != mididx)
				printf("%d ",ans[i][j]);
		}
	}
	return 0;
}
