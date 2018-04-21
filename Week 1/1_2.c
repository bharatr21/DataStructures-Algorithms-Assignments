#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

int main()
{
	char s1[100]={};
	char s2[100]={};
	scanf("%[^\n]s",s2);
	getchar();
	scanf("%[^\n]s",s1);
	//printf("%s\n",s2);
	//printf("%s",s1);
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	int ct=0,i,len;
	for(i=0;i<l1;)
	{
		if(s2[0]==s1[i])
		{
			int j=0; len=0;
			while(s2[j]==s1[i])
			{
				len++;
				j++;
				i++;
			}
			if(len==l2&&s1[i]==' ') ct++;
		}
		else
			i++;
	}
	printf("%d\n",ct);
	return 0;
}