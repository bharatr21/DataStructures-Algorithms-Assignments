#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

void rev(char* s, int beg, int end)
{
    int j=beg, k=end-1;
    char temp;
    while(j<k)
    {
        temp = s[j];
        s[j] = s[k];
        s[k] = temp;
        j++;
        k--;
    }
}

int main()
{
    char s[1001], temp,i;
    scanf("%[^\n]s",s); getchar();
    int n = strlen(s);
    int j=0;
    rev(s,0,n);
    /*f(i,0,n/2)
    {
        temp=s[i];
        s[i]=s[n-1-i];
        s[n-1-i]=temp;
    }*/
    f(i,0,n)
    {
        if(s[i+1]=='\0')
        {
            rev(s,j,i+1);
        }
        else if((s[i]==' ')||(s[i]=='\n'))
        {
            rev(s,j,i);
            j=i+1;
        }
    }
    printf("%s\n",s);
    return 0;
}