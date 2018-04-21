#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tp=-1;
int size;
int* s=NULL;
void CreateStack(int siz){
	s = (int*)malloc(siz*sizeof(int));
	tp=-1;
	size = siz;
}

void Push(int ele){
	s[++tp] = ele;
}

int empty() {return (tp==-1); }

int Pop(){ size--; return (empty()?-1:s[tp--]); }

int Top() {return (empty()?-1:s[tp]); }

int main(){
	CreateStack(10000);
	int arr[10][10];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int ct=0,i=0,j=0;
	while(i!=9 || j!=9) {
		if(j+1<10 && arr[i][j+1]==1){
			arr[i][j+1]=0;
			Push(1);
			j++;
		}
		else if(i+1<10 && arr[i+1][j]==1){
			arr[i+1][j]=0;
			Push(2);
			i++;
		}
		else if(j-1>=0 && arr[i][j-1]==1){
			arr[i][j-1]=0;
			Push(3);
			j--;
		}
		else if(i-1>=0 && arr[i-1][j]==1){
			arr[i][j]=0;
			Push(4);
			i--;
		}
		else
		{
			int ele=Pop();
			if(ele==1){
				j--;
			}
			else if(ele==2){
				i--;
			}
			else if(ele==3){
				j++;
			}
			else{
				i++;
			}
		}
		//printf("%d %d\n",i,j);
	}
	char Path[100];
	int idx=0;
	while(tp!=-1){
		int ele=Pop();
		if(ele==1){
			Path[idx++]='R';
		}
		else if(ele==2){
			Path[idx++]='D';
		}
		else if(ele==3){
			Path[idx++]='L';
		}
		else if(ele==4){
			Path[idx++]='U';
		}
	}
	idx--;
	for(int i=idx;i>=0;i--){
		printf("%c",Path[i]);
	}
	return 0;
}