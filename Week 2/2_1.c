#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int repr[8];
int expr[17];

void base_3(int num){
	int idx=0;
	while(idx<8){
		repr[idx++]=num%3;
		num=num/3;
	}
}

void process(){
	int val=0;
	int idx=0,prev=-5;
	for(int i=1;i<17;i+=2){
		if(repr[idx]==0){
			expr[i]=-1;
		}
		else if(repr[idx]==1){
			expr[i]=-2;
		}
		else if(repr[idx]==2){
			expr[i]=-3;
		}
		idx++;
	}
	int curr=0,j;
	for(int i=0;i<17;){
		if(i==0){
			curr=0;
			while(i<17){
				curr=curr*10+expr[i];
				if(i==16){
					break;
				}
				if(expr[i+1]!=-3){
					prev=expr[i+1];
					i+=2;
					break;
				}
				else{
					i+=2;
				}
			}
			val=curr;
		}
		else{
			curr=0;
			while(i<17){
				curr=curr*10+expr[i];
				if(i==16){
					if(prev==-1){
						val+=curr;
						//printf("h%d",curr);
					}
					else{
						val-=curr;
					}
					i++;
					continue;
				}
				if(expr[i+1]!=-3){
					if(prev==-1){
						val+=curr;
						curr=0;
						prev=expr[i+1];
						i+=2;
						break;
					}
					else if(prev==-2){
						val-=curr;
						curr=0;
						prev=expr[i+1];
						i+=2;
						break;	
					}
				}
				else{
					i+=2;
				}
			}
			//printf("\nval=%d curr=%d\n",val,curr);
		}
	}
	//printf("val=%d",val);
	if(val==100){
		for(int i=0;i<17;i++){
			if(i%2==0){
				printf("%d",expr[i]);
			}
			else{
				if(expr[i]==-1){
					printf("+");
				}
				else if(expr[i]==-2){
					printf("-");
				}
				else{
					continue;
				}
			}
		}
		printf("\n");
	}
}

int main(){
	int idx=0,ans;
	for(int i=1;i<=9;i++){
		expr[idx]=i;
		idx+=2;
	}
	for(int i=0;i<=6560;i++){
		base_3(i);
		process();
	}
	//base_3(1467);
	/*for(int i=0;i<8;i++){
		printf("%d",repr[i]);
	}*/
	//process();
	return 0;
}