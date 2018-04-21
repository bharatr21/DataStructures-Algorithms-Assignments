#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)

int max(int x, int y) {return (x > y) ? x : y; }

void lcsub(char s1[], char s2[], char s3[], int m, int n, int p)
{
	int lcs[m+1][n+1][p+1];
	f(i,0,m+1)
	{
		f(j,0,n+1)
		{
			f(k,0,p+1)
			{
				if(i == 0 || j == 0 || k == 0) lcs[i][j][k] = 0; 
				else if(s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1])
					lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
				else
					lcs[i][j][k] = max(max(lcs[i-1][j][k], lcs[i][j-1][k]), lcs[i][j][k-1]);
			}
		}
	}
	printf("%d\n",lcs[m][n][p]);
	int idx = lcs[m][n][p];
	char res[idx + 1];
	res[idx] = '\0';
	int i = m, j = n, k = p;
	while(i > 0 && j > 0 && k > 0)
	{
		if(s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1])
		{
			res[idx-1] = s1[i-1];
			idx--; i--; j--; k--;
		}
		else if(lcs[i-1][j][k] >= lcs[i][j-1][k] && lcs[i-1][j][k] >= lcs[i][j][k-1])
			i--;
		else if(lcs[i][j-1][k] >= lcs[i-1][j][k] && lcs[i][j-1][k] >= lcs[i][j][k-1])
			j--;
		else
			k--;
	}
	printf("%s\n", res);
}

int main()
{
	char s1[100], s2[100], s3[100];
	scanf("%s", s1);
	scanf("%s", s2);
	scanf("%s", s3);
	int m = strlen(s1);
	int n = strlen(s2);
	int p = strlen(s2);
	lcsub(s1, s2, s3, m, n, p);
	return 0;
}