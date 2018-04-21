#include<stdio.h>
#include<string.h>
void comb(int sym[],int pos,int n)
{   int i,j;
    if(pos==9)
    {  int tracker=0,nos[9];
        int res=0;
        int sum;
          for(i=0;i<=8;i++)
             {
                if(sym[i]==1)
                {
                    nos[tracker++]=i+1;
                }
                 else if(sym[i]==2)
                 {
                    nos[tracker++]=-(i+1);
                 }
                else
                  {
                     tracker--;
                     if(nos[tracker]<0)
                          nos[tracker]=nos[tracker]*10-i-1;
                      else
                           nos[tracker]=nos[tracker]*10+i+1;
                        tracker++;
            
                   }                
          
             }
         for(i=0;i<tracker;i++)
               res=res+nos[i];
         if(res==n)
          {  for(i=0;i<tracker;i++)
          
            {
                if(nos[i]<0)
                {  if(i!=tracker-1)
                    printf("  %d -",-1*nos[i]);
                    else
                        printf("  %d ",-1*nos[i]);
                }
                else
                {   if(i!=tracker-1)
                      printf("  %d +",nos[i]);
                    else 
                       printf("  %d ",nos[i]);
                }
            }
            printf(" = %d\n",res);
         }
    }
    else
       { 
         for(j=1;j<=3;j++)
          {
             sym[pos]=j;
             comb(sym,pos+1,n);                 
          }
       }   
}
int main()
{
     int i,j,k,n;
     scanf("%d",&n);
     int sym[9];
     comb(sym,1,n);
    return 0;
}
