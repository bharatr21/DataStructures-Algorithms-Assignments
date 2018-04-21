#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int main()
{
	char s1[100],s2[100],s3[100],s4[100];
	scanf("%[^\n]s",s1);
	int l = strlen(s1);
	int n = sqrt(l),i,j;
	int m[n][n];
	int flag=1;
	int k=0;
	f(i,0,n)
	{
		f(j,0,n)
		{
			m[i][j] = s1[k++];
		}
	}
	s1[k]='\0';
	k=0;
	fd(i,n-1,0)
	{
		fd(j,n-1,0)
		{
			s2[k++] = m[i][j];
		}
	}
	s2[k]='\0';
	if(strcmp(s1,s2)) { printf("1-2\n"); flag=0;}
	k=0;
	f(j,0,n)
	{
		f(i,0,n)
		{
			s3[k++] = m[i][j];
		}
	}
	s3[k]='\0';
	if(strcmp(s2,s3)) {printf("2-3\n"); flag=0;}
	k=0;
	fd(j,n-1,0)
	{
		fd(i,n-1,0)
		{
			s4[k++] = m[i][j];
		}
	}
	s4[k]='\0';
	if(strcmp(s3,s4)) {printf("3-4\n");flag=0;}
	if(flag) {
		printf("YES\n");
	}
	else
		printf("NO\n");
	return 0;	

}