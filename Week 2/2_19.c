#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

int main()
{
	char rmap[][5] = {
		{' ','0','#','#','#'},
		{'$','1','$','$','$'},
		{'a','b','c','2','#'},
		{'d','e','f','3','#'},
		{'g','h','i','4','#'},
		{'j','k','l','5','#'},
		{'m','n','o','6','#'},
		{'p','q','r','s','7'},
		{'t','u','v','8','#'},
		{'w','x','y','z','9'},
	};
	char str[100];
	scanf("%[^\n]s",str);
	int i,s;
	s=0;
	for(i=0;str[i]!='\0';i++)
	{
		//Keep track of the number of times each digit is pressed
		while(s<5&&str[i+1]!='\0')
		{
			if(str[i+1]!=str[i]) {
				break;
			}
			else {
				s++;
				i++;
			}
		}
		printf("%c",rmap[str[i]-'0'][s]);
		s=0;
	}
	printf("\n");
	return 0;	
}