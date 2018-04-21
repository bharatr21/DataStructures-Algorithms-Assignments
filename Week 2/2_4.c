#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

const char* name(int n)
{
    switch(n)
    {
        case 9: return "Nine";
        case 8: return "Eight";
        case 7: return "Seven";
        case 6: return "Six";
        case 5: return "Five";
        case 4: return "Four";
        case 3: return "Three";
        case 2: return "Two";
        case 1: return "One";
        case 0: return " ";
    }
}

int main()
{
    int a[4]={0},i,n;
    printf("Enter a number <0-9999>\n");
    scanf("%d",&n);
    if(n == 0) { printf("Zero"); return 0; }
    if( (n>=10000) || (n<0) ){ printf("Invalid number"); return 0;}
    i=0;
    while(n)
    {
        a[i]=n%10;
        i++;
        n/=10;
    }
    int flag=0;
    if(a[3]==0) {;}
    else {
        printf("%s Thousand ",name(a[3]));
        if((a[2]==0)&&(a[1]||a[0])) {
            printf("and");
        }
    }
    if(a[2]==0) {;}
    else {
        printf("%s Hundred ",name(a[2]));
        if(a[1]||a[0]) {
            printf("and");
        }
    }
    switch(a[1])
    {
        case 9: { printf(" Ninety "); break; }
        case 8: { printf(" Eighty "); break; }
        case 7: { printf(" Seventy "); break; }
        case 6: { printf(" Sixty "); break; }
        case 5: { printf(" Fifty "); break; }
        case 4: { printf(" Forty "); break; }
        case 3: { printf(" Thirty "); break; }
        case 2: { printf(" Twenty "); break; }
        case 0: { printf(" "); break; }
        case 1: {
            switch(a[0])
            {
                case 9: {printf(" Nineteen "); flag=1; break;}
                case 8: {printf(" Eighteen "); flag=1; break; }
                case 7: {printf(" Seventeen "); flag=1; break; }
                case 6: {printf(" Sixteen "); flag=1; break; }
                case 5: {printf(" Fifteen "); flag=1; break; }
                case 4: {printf(" Fourteen "); flag=1; break; }
                case 3: {printf(" Thirteen "); flag=1; break; }
                case 2: {printf(" Twelve "); flag=1; break; }
                case 1: {printf(" Eleven "); flag=1; break; }
                case 0: {printf(" Ten "); flag=1; break; }
            }
            break;
        }
    }
    if(flag) {;}
    else {
        if(a[0]==0) {;}
        printf("%s ",name(a[0]));
    }
    return 0;
}