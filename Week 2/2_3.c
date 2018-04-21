#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

void rem(char* s, int size, char* res)
{
    char temp[2];
    int s_cm = 0;
    int m_cm = 0;
    int i;
    f(i,0,size)
    {
        if(s_cm == 1 && s[i] == '\n')
            s_cm = 0; 
        else if(m_cm == 1 && s[i] == '*' && s[i+1] == '/') {
            m_cm = 0; i++;
        }
        else if(m_cm || s_cm)
            continue;
        else if(s[i] == '/' && s[i+1] == '/') {
            s_cm = 1; i++;
        }
        else if(s[i] == '/' && s[i+1] == '*') {
            m_cm = 1; i++;
        }
        else {
            temp[0] = s[i];
            temp[1] = '\0';
            res = strcat(res, temp);
        }
    }
    temp[0] = '}';
    temp[1] = '\0';
    res = strcat(res, temp);
}

int main()
{
    char s[1000], res[1000];
    scanf("%[^}]s",s);
    getchar();
    int size = strlen(s);
    rem(s,size,res);
    int sz = strlen(res), ind, i;
    f(i,0,sz) {
        if(res[i] == '#')
        {
            ind = i; break;
        }
    }
    printf("\n");
    f(i,ind,sz)
        printf("%c",res[i]);
    printf("\n");
    return 0;
}