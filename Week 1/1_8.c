#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

int main()
{
	int a[7],i,l;
	memset(a,-1,sizeof(a));
	char s[100];
	scanf("%s",s);
	l = strlen(s);
	f(i,0,l)
	{
		switch(s[i])
		{
			case 'g': { a[0]=i; break; }
			case 'o': { if(a[1]==-1) { 
							a[1]=i; break;
						}
						else {
							a[2]=i; break;
						}	 
					  }
			case 'd': { a[3]=i; break; }
			case 'b': { a[4]=i; break; }
			case 'y': { a[5]=i; break; }
			case 'e': { a[6]=i; break; }
		}
	}
	int flag=0;
	f(i,0,5)
	{
		if((a[i]==-1)||(a[i]>a[i+1])) {
			flag=1; break;
		}
	}
	if(flag) printf("No\n");
	else printf("Yes\n");
	return 0;
}