#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>a;i--)
#define nl '\n'

struct item{
    int row;
    int col;
    int value;

}b[9];
int main()
{
    int a[6][6]={0},c[6][6],i,j,cnt=0;
    int k=0;
    f(i,0,6)
    {
        f(j,0,6)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]) cnt++;
        }
    }
    //Transpose
    f(i,0,6)
    {
        f(j,0,6)
        {
            c[i][j]=a[j][i];
        }
    }
    if(cnt>=10)
    {
        printf("Not Sparse\n");
        return 0;
    }
    else {
            f(i,0,6)
            {
                f(j,0,6)
                {
                    if(c[i][j])
                    {
                        b[k].row = i;
                        b[k].col = j;
                        b[k++].value = c[i][j];
                    }
                }
            }
/*            //Transpose
            f(i,0,k)
            {
                b[i].row = b[i].row^b[i].col;
                b[i].col = b[i].row^b[i].col;
                b[i].row = b[i].row^b[i].col;
            }*/
            f(i,0,k)
            {
                printf("%d %d %d\n",b[i].row,b[i].col,b[i].value);
            }
        }   
    return 0;
}