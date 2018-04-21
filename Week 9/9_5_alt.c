 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<float.h>
#include<math.h>
#include<inttypes.h>
#include<assert.h>
#include<ctype.h>
#include<limits.h>
#include<time.h>
#define ll long long
#define For(i,n)	for(i=0;i<n;i++)
#define rep(i ,a ,b)	for(i=(a);i<=(b);i++)
#define mset(a ,value)	memset(a ,value ,sizeof(a))
#define s(a)	scanf("%d" ,&a);
#define ls(a)	scanf("%ld" ,&a)
#define reg(i)	register int i
#define INF 0xfffffffffffffLL
#define MAX 100005
#define N 1000001
#define least -1
#define NIL -1
ll min(ll a,ll b){	return (a<b?a:b);	}
ll max(ll a,ll b){	return (a>b?a:b);	} 
int A[MAX][50] ,size[MAX] = {0} ,c[50]  ,pr[N] = {0};
ll B[MAX];
ll a ,b;
void sieve(){
	ll i ,j ,x ;
	int c;
	mset(pr ,1);
	for(i=2;i<N;i++){
		if(pr[i]){
			for(j=i*i;j<N;j+=i)	pr[j]=0;
			x = (ll)ceil(((double)a)/((double)i));
			for(j=i*x;j<=b;j+=i){
				c=0;
				while((B[j-a])%i==0){	c++ ;	B[j-a] = (B[j-a])/i;	}
				A[j-a][size[j-a]]=c;
				size[j-a]++;
			}
		}
	}
	for(i=a;i<=b;i++){
		if(B[i-a]>1){	A[i-a][size[i-a]]=1;	size[i-a]++;	}
	}
}
int main(){
	ll i ,j ,k;
	int r;
	int m;
	scanf("%lld %lld" ,&a ,&b);
	ll sum=0LL ,ans=1LL;
	for(i=a;i<=b;i++)	B[i-a] = i;
	sieve();
	bool f=0;
	for(i=a;i<=b;i++){
			ans=1LL ,m=0;
			for(j=0;j<size[i-a];j++){
				ans*=(A[i-a][j]+1);
				c[A[i-a][j]]++;
				if(A[i-a][j]>m)	m=A[i-a][j];
			}
			sum+=(ans-1);
			for(j=m;j>0;j--){
				while(c[j]){
					ans/=(j+1);
					ans*=j;
					sum+=ans;
					c[j]--;
					c[j-1]++;
				}
			}
		}
	printf("%lld\n" ,sum);
	return 0;
}