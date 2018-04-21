#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

int main()
{
	int map[27] = {
		2,22,222,
		3,33,333,
		4,44,444,
		5,55,555,
		6,66,666,
		7,77,777,7777,
		8,88,888,
		9,99,999,9999};
	int num[10] = {00,11,2222,3333,4444,5555,6666,77777,8888,99999};
	int group[31] = {
		2,2,2,
		3,3,3,
		4,4,4,
		5,5,5,
		6,6,6,
		7,7,7,7,
		8,8,8,
		9,9,9,9};
	int groupd[] = {
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
	};
	char str[100];
	scanf("%[^\n]s",str);
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==' ')
		{
			printf("0");
		}
		if(isalpha(str[i])&&isalpha(str[i-1]))
		{
			if(group[str[i]-97]==group[str[i-1]-97])
				printf(" ");
		}
		if(isdigit(str[i])&&isdigit(str[i-1]))
		{
			if(groupd[str[i]-'0']==groupd[str[i-1]-'0'])
				printf(" ");
		}
		if(isdigit(str[i]))
			printf("%d",num[str[i]-'0']);
		if(isalpha(str[i]))
			printf("%d",map[str[i]-97]);
	}
	printf("\n");
	return 0;	
}