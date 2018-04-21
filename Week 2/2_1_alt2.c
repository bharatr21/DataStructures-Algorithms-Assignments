#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

void base3(int i,int t[])
{
	int j=0;
	while((j<8)&&(i))
	{
		t[j++] = i%3;
		i = i/3;
	}
}

void process(char* s1, int t[])
{
	int k=0,i;
	int n=strlen(s1);
	for(i=1;i<n;i+=2)
	{
		if(t[k]==0) s1[i]='c';
		if(t[k]==1) s1[i]='+';
		if(t[k]==2) s1[i]='-';
		k++;
	}
}

void parser(char* s1, char* s)
{
	int n = strlen(s1),i;
	int k=0;
	f(i,0,n)
	{
		if(s1[i]!='c')
		{
			s[k++] = s1[i];
		}
	}
}

int main()
{
	int i,j;
	char* s = malloc(17*sizeof(char));
	int tri[8]= {0};
	f(i,0,6561)
	{
		char s1[] = "1#2#3#4#5#6#7#8#9";
		base3(i, tri);
		process(s1, tri);
		parser(s1,s);
		printf("%s\n",s);
	}
	free(s);
	return 0;
}
