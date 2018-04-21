#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int main()
{
	int a[8][8];
	int b[8][8];
	int i,j,p,q,ind,jnd;
	f(i,0,8)
	{
		f(j,0,8)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int fl=0;
	int n=8;
	f(i,0,8)
	{
		f(j,0,8)
		{
			if(a[i][j]==1)
			{
				ind=i; jnd=j;
				//row
				f(p,0,8) 
				{
					if(p!=ind && a[p][jnd]==1) { 
						//printf("%d %d\n",p,jnd);
						fl=1;
					}
				}
				//col
				f(q,0,8) 
				{
					if(q!=jnd && a[ind][q]==1) 
						{
							//printf("%d %d\n",ind,q);
							fl=1;
						}
				}
				for(p=ind,q=jnd;p>=0&&q<n;p--,q++)
				{
					if(a[p][q]==1) {
						if((p!=ind)||(q!=jnd)) {
							//printf("%d %d\n",p,q);
							fl=1;
						}
					}
				}
				for(p=ind,q=jnd;p<n&&q>=0;p++,q--)
				{
					if(a[p][q]==1) {
						if((p!=ind)||(q!=jnd)) {
							//printf("%d %d\n",p,q);
							fl=1;
						}
					}
				}
				for(p=ind,q=jnd;p>=0&&q>=0;p--,q--)
				{
					if(a[p][q]==1) {
						if((p!=ind)||(q!=jnd)) {
							//printf("%d %d\n",p,q);
							fl=1;
						}
					}
				}
				for(p=ind,q=jnd;p<n&&q<n;p++,q++)
				{
					if(a[p][q]==1) {
						if((p!=ind)||(q!=jnd)) {
							//printf("%d %d\n",p,q);
							fl=1;
						}
					}
				}
			}
		}
		if(fl) break;
	}
	if(fl) printf("NO\n");
	else printf("YES\n");
	return 0;
}