#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)

int max(int x, int y) {return (x > y) ? x : y; }

void lcsub(char s1[], char s2[], int m, int n)
{
	int lcs[m+1][n+1];
	int k=0;
	f(i,0,m+1)
	{
		f(j,0,n+1)
		{
			if(i == 0 || j == 0) lcs[i][j] = 0; 
			else if(s1[i-1] == s2[j-1])
				lcs[i][j] = lcs[i-1][j-1] + 1;
			else
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
	}
	printf("%d\n",lcs[m][n]);
	int idx = lcs[m][n];
	char res[idx + 1];
	res[idx] = '\0';
	int i = m, j = n;
	while(i > 0 && j > 0)
	{
		if(s1[i-1] == s2[j-1])
		{
			res[idx-1] = s1[i-1];
			idx--; i--; j--;
		}
		else if(lcs[i-1][j] > lcs[i][j-1])
			i--;
		else
			j--;
	}
	printf("%s\n", res);
}

int main()
{
	char s1[100], s2[100];
	scanf("%s", s1);
	scanf("%s", s2);
	int m = strlen(s1);
	int n = strlen(s2);
	lcsub(s1, s2, m, n);
	return 0;
}