#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int min(int x,int y){
	if(x<y){
		return x;
	}
	return y;
}

int main(){
	int n,mn=9999;
	scanf("%d",&n);
	int arr[n][n];
	int row[n],col[n];
	int row_1[n],col_1[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
		row[i]=0;
		col[i]=0;
		row_1[i]=0;
		col_1[i]=0;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			row[i]+=arr[i][j];
			col[i]+=arr[j][i];
		}
	}
	int ct=n,mn_r,mn_c,idx1,idx2;
	while(ct>=2){
		mn_r=row[0];
		mn_c=col[0];
		idx1=0;
		idx2=0;
		for(int i=0;i<n;i++){
			if(row_1[i]==0 && row[i]<mn_r){
				mn_r=row[i];
				idx1=i;
			}
			if(col_1[i]==0 && col[i]<mn_c){
				mn_c=col[i];
				idx2=i;
			}
		}
		if(mn_r<mn_c){
			if(mn_r>=0){
				break;
			}
			row_1[idx1]=1;
			for(int i=0;i<n;i++){
				col[i]-=arr[idx1][i];
			}
			int a,mn=9999;
			for(int i=0;i<n;i++){
				if(col_1[i]==0 && col[i]<mn){
					mn=col[i];
					a=i;
				}
			}
			col_1[a]=1;
			for(int i=0;i<n;i++){
				row[i]-=arr[i][a];
			}
		}
		else{
			if(mn_c>=0){
				break;
			}
			col_1[idx2]=1;
			for(int i=0;i<n;i++){
				row[i]-=arr[i][idx2];
			}
			int a,mn=9999;
			for(int i=0;i<n;i++){
				if(row_1[i]==0 && row[i]<mn){
					mn=row[i];
					a=i;
				}
			}
			row_1[a]=1;
			for(int i=0;i<n;i++){
				col[i]-=arr[a][i];
			}
		}
		ct--;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(row_1[i]==0){
			ans+=row[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}