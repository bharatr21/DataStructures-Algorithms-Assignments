#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

void getSoundex(char* ans, char* input)
{
	char map[] = "01230120022455012623010202";
	int i=0;
	while(input[i]!='\0')
	{
		input[i] = toupper(input[i]);
		i++;
	}
	i=0;
	//Preprocessing Step 1 - Replacements
	while(input[i]!='\0')
	{
			if(input[i]=='D'&&input[i+1]=='G')
				input[i] = ' ';
			if(input[i]=='G'&&input[i+1]=='H'&&i!=0)
				input[i] = ' ';
			if(input[i]=='G'&&input[i+1]=='N')
				input[i] = ' ';
			if(input[i]=='K'&&input[i+1]=='N')
				input[i] = ' ';
			if(input[i]=='P'&&input[i+1]=='H')
				{ input[i] = 'F'; input[i] = ' '; }
			if(input[i]=='M'&&input[i+1]=='P')
			{
				if((input[i+2]=='S')||(input[i+2]=='Z')||(input[i+2]=='T'))
				{
					input[i+1] = ' ';
				}
			}
			if(input[i]=='P'&&input[i+1]=='S'&&i==0)
				input[i] = ' ';
			if(input[i]=='P'&&input[i+1]=='F'&&i==0)
				input[i] = ' ';
			if(input[i]=='M'&&input[i+1]=='B')
				input[i+1] = ' ';
			if(i>=1)
			{
				if((input[i-1]=='T')&&(input[i-1]=='C')&&(input[i-1]=='H'))
				{
					input[i-1] = ' ';
				}
			}
	}
	ans[0] = toupper(input[0]);
	int ct=1;
	i=1;
	while(input[i]!='\0')
	{
		if(isupper(input[i]))
		{
			int c = input[i] - 'A';
			if(map[c]!='0')
			{
				if(map[c]!=ans[ct-1])
				{
					ans[ct] = map[c];
					ct++;
				}
				i++;
			}
			if(ct > 3) break;
			if(ct <= 3)
			{
				while(ct <= 3)
				{
					ans[ct] = '0';
					ct++;
				}
			}
		}
		ans[4] = '\0';
	}
}

int main()
{
	char s[100];
	scanf("%s",s);	
	char ans[5];
	getSoundex(ans,s);
	printf("%s\n",ans);
	return 0;
}