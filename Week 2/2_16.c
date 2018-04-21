#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int main()
{
    int n,state,i,j;
    scanf("%d",&n);
    int** a = malloc((n+1)*sizeof(int*));
    f(i,0,n+1)
    {
        a[i] = malloc((n+1)*sizeof(int));
    }
    f(i,0,n+1)
    {
        f(j,0,n+1)
        {
            a[i][j] = 0;
        }
    }
    int k=1;
    state = 0;
    i=0; j=0;
    while(k<=n*n) {
      switch(state)
      {
          case 0:
          {
              if((j==n)||(a[i][j])) {state = (state+1)%4; j--; i++; break;}
              else if(j<n){
                     a[i][j] = k;
                     k++;
                     j++;
                     break;
                  }
          }
          case 1:
          {
              if((i==n)||(a[i][j])) {state = (state+1)%4; i--; j--; break;}
              else if(i<n){
                     a[i][j] = k;
                     k++;
                     i++;
                     break;
                  }   
          }
          case 2:
          {
              if((j==-1)||a[i][j]) {state = (state+1)%4; j++; i--; break;}
              else if(i>=0){
                     a[i][j] = k;
                     k++;
                     j--;
                     break;
                  }
          }
          case 3:
          {
              if((i==-1||a[i][j])) {state = (state+1)%4; i++; j++; break;}
              else if(j>=0){
                     a[i][j] = k;
                     k++;
                     i--;
                     break;
                  }
          }
      }   
    }
    f(i,0,n)
    {
        f(j,0,n)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}