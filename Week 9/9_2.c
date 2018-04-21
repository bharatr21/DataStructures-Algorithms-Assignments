#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int cmp(const void* a, const void* b)
{
	return (*(char*)a - *(char*)b);
}

void swap(char* a, char* b)
{
	char c = *a;
	*a = *b;
	*b = c;
}

int find(char str[], char first, int l, int h)
{
	int ceil = l, i;
	f(i,l+1,h+1)
		if(str[i] > first && str[i] < str[ceil]) 
			ceil = i;

	return ceil;	
}

void nextperm(char str[])
{
	int sz = strlen(str);
	qsort(str, sz, sizeof(str[0]), cmp);
	int flag = 0;
	while(!flag)
	{
		printf("%s\n",str);
		int i;
		fd(i, sz - 2, 0) 
			if(str[i] < str[i+1]) 
				break;
		if(i == -1)
		{
			flag = 1;
		}
		else
		{
			int ceil = find(str, str[i], i + 1, sz - 1);
			swap(&str[i], &str[ceil]);
			qsort(str + i + 1, sz - i - 1, sizeof(str[0]), cmp);
		}
	}
}

int main()
{
	char str[100];
	scanf("%s",str);
	printf("\n");
	nextperm(str);
	return 0;
}
