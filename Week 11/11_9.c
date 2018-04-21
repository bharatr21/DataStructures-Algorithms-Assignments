#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

int mini(int x, int y) {return (x < y) ? x : y ;}

int min(int x, int y, int z) {return mini(mini(x, y), z); }

int edit(char s1[], char s2[], int m, int n)
{
	int tab[m+1][n+1];
	f(i,0,m+1)
	{
		f(j,0,n+1)
		{
			if(!i) tab[i][j] = j;
			else if(!j) tab[i][j] = i;
			else if(s1[i-1] == s2[j-1])
				tab[i][j] = tab[i-1][j-1];
			else
				tab[i][j] = 1 + min(tab[i-1][j], tab[i][j-1], tab[i-1][j-1]);
		}
	}
	return tab[m][n];
}

int main()
{
	char s1[100], s2[100];
	scanf("%s",s1);
	int n1 = strlen(s1);
	scanf("%s",s2);
	int n2 = strlen(s2);
	printf("%d\n", edit(s1, s2, n1, n2));
	return 0;
}
