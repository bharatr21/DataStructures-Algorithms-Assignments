#include <stdio.h>
#include <stdlib.h>
#include<string.h>	
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

char process(char s)
{
	int a[] = {0,2,4,6,8,1,3,5,7,9};
	return a[s-'0']+'0';
}

int main()
{
	char s[100],temp;
	scanf("%s",s);
	int lt = strlen(s),i;
	int sum=0;
	int check = s[lt-1] - '0';
	//String Reversal
	--lt;	
	f(i,0,lt/2)
	{
		temp = s[i];
		s[i] = s[lt-i-1];
		s[lt-1-i] = temp;
	}
	for(i=0;i<lt;i+=2)
	{
		s[i]=process(s[i]);
	}
	f(i,0,lt) sum+=(s[i]-'0');
	if((sum+check)%10)
	{
		printf("Invalid\n");
	}
	else{
		printf("Valid\n");
	}
	return 0;
}