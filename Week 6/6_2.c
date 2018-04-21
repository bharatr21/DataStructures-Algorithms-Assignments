#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ll long long int
ll arr[100000][26];
ll fact[100001]={0};
ll mod=1000000007;

void factorial(){
	fact[1]=1;
	for(ll i=2;i<=100000;i++){
		fact[i]=(fact[i-1]*(i%mod))%mod;
	}
}

ll modular(ll a,ll b){
	if(b==1){
		return (a%mod);
	}
	if(b==0){
		return 1;
	}
	if(b%2==0){
		ll ans=(modular(a,b/2)%mod);
		return ((ans%mod)*(ans%mod))%mod;
	}
	return ((a%mod)*(modular(a,b-1)%mod)%mod);
}

void process(ll ct[]){
	for(ll i=0;i<26;i++){
		printf("%lld ",ct[i]);
	}
	ll num=0;
	ll len=0;
	ll ans=1;
	for(ll i=0;i<26;i++){
		num+=ct[i]%2;
	}
	printf("num=%lld\n",num);
	if(num==0){
		for(ll i=0;i<26;i++){
			if(ct[i]!=0){
				ans=(ans*modular(fact[ct[i]/2],mod-2))%mod;
				len+=ct[i];
			}
		}
		ans=(ans*fact[len/2])%mod;
	}
	else{
		for(ll i=0;i<26;i++){
			if(ct[i]%2==0){
				ans=(ans*modular(fact[ct[i]/2],mod-2))%mod;
				len+=ct[i];
			}
			else{
				ans=(ans*modular(fact[(ct[i]-1)/2],mod-2))%mod;
				len+=ct[i]-1;
			}
		}
		printf("%lld\n",len);
		exit(0);
		len++;
		ans=(ans*fact[len/2])%mod;
		ans=((ans%mod)*(num%mod))%mod;
	}
	printf("%lld\n",ans);
}

int main(){
	factorial();
	char str[100000];
	scanf("%s",str);
	ll l=strlen(str);
	for(ll i=0;i<l;i++){
		for(ll j=0;j<26;j++){
			arr[i][j]=0;
		}
	}
	for(ll i=0;i<l;i++){
		arr[i][str[i]-'a']++;
	}
	for(ll i=1;i<l;i++){
		for(ll j=0;j<26;j++){
			arr[i][j]+=arr[i-1][j];
		}
	}
	ll q,r;
	scanf("%lld",&q);
	ll ct[26]={0};
	while(q--)
	{
		scanf("%lld %lld",&l,&r);
		l--;
		r--;
		for(ll j=0;j<26;j++){
			if(l!=0){
				ct[j]=arr[r][j]-arr[l-1][j];
			}
			else{
				ct[j]=arr[r][j];
			}
		}
		// printf("hello\n");
		process(ct);
	}
	return 0;
}