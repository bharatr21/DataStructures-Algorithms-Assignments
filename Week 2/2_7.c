#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

int main()
{
	char s[100], p[100];
	int l,k,depth,m,i;
	scanf("%[^\n]s",s);
	scanf("%d",&depth);
	l = strlen(s);
	k = 0;
	f(i,0,l)
	{
		if(s[i] == ' ') {;}
		else {
			p[k++] = s[i];
		}
	}
	int d = depth;
	m = 0;
	while(d--)
	{
		for(i=m;i<k;i+=depth) printf("%c",p[i]);
		m++;
	}
	return 0;
}