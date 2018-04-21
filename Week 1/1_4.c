#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

void rev(char* s, int begin, int end)
{
	char temp;
	while(begin < end)
	{
		temp = s[begin];
		s[begin] = s[end];
		s[end] = temp;
		begin++;
		end--;
	}
}

void encode(char* s)
{
	int i, l = strlen(s);
	f(i,0,l)
	{
		if(isalpha(s[i]))
		{
			s[i] = (s[i]-'a'+3)%26+'a';
		}
	}
}

void decode(char* s)
{
	int i, l = strlen(s);
	f(i,0,l)
	{
		if(isalpha(s[i]))
		{
			s[i] = (s[i]-'a'+23)%26+'a';
		}
	}
}

int main()
{
	char s[100];
	scanf("%[^\n]s",s);
	int i,l = strlen(s);
	int begin=0,end;
	f(i,0,l)
	{
		if(s[i]==' '||s[i]=='\0'||s[i]=='\n') {
			end=i-1;
			rev(s,begin,end);
			begin = i+1;
		}
	}
	//encode(s);
	decode(s);
	f(i,0,l) printf("%c",s[i]);
	printf("\n");
	return 0;
}