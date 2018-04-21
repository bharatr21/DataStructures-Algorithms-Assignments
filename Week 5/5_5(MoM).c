#include <stdio.h>
#include <stdlib.h>

#define swap(a,b) t=b;b=a;a=t;

int t;
int f1(const void *p1,const void *p2){
	return *(int*)p1>*(int*)p2;
}

typedef struct pair{
	int first,second;
}pair;

int f2(const void *p1,const void *p2){
	return ((pair*)p1)->first>((pair*)p2)->first;
}

int partition(int *v,int l,int u,int m){
	swap(v[m],v[u-1]);
	int k=l;
	for(int i=l;i<u-1;i++){
		if(v[i]<v[u-1]){
			swap(v[i],v[k]);
			k++;
		}
	}
	swap(v[k],v[u-1]);
	return k;
}

int findmedian(int v[], int L);

int findk(int v[],int L,int k){ //k in range [0,n-1]
	if(L<10){ //Base case of recursion
		pair p[L];
		for(int i=0;i<L;i++){
			p[i].first=v[i];
			p[i].second=i;
		}
		qsort(p,L,sizeof(pair),f2);
		int ans=p[k].second;
		//free(p);
		return ans;
	}else{
		
		int vw[(L+(5-L%5))/5];
		pair p[L];
		for(int i=0;i<L;i++){
			p[i].first=v[i];
			p[i].second=i;
		}
		for(int i=0;i<(L+(5-L%5))/5;i++){
			if(i!=L/5){
				qsort(p+(i*5),5,sizeof(pair),f2); //Sorting arrays of size 5
				vw[i]=p[5*i+2].first;
			}else{
				qsort(p+(i*5),L%5,sizeof(pair),f2); //Sorting arrays of size 5
				vw[i]=p[5*i+(L%5/2)].first;
			}
		}

		int med=findmedian(vw,L/5);
		int tofind=vw[med];
		for(int i=0;i<L;i++){
			if(p[i].first==tofind){
				med=p[i].second;
				break;
			}
		}

		int v1[L];
		for(int i=0;i<L;i++){
			p[i].first=v[i];
			p[i].second=i;
			v1[i]=v[i];
		}


		med=partition(v1,0,L,med);

		int ans;
		//int *va;
		if(med==k){
			//va=calloc(sizeof(int),1);
			ans=med;
		}else if(med<k){
			int va[L-med-1];
			for(int i=med+1;i<L;i++){
				va[i-med-1]=v1[i];
			}
			ans=findk(va,L-med-1,k-med-1);
			ans+=med+1;
			
		}else{
			int va[med];
			for(int i=0;i<med;i++){
				va[i]=v1[i];
			}
			ans=findk(va,med,k);
		}
		//printf("%d ",v[ans]);
		for(int i=0;i<L;i++){
			if(p[i].first==v1[ans]){
				ans=p[i].second;
				break;
			}
		}
		/*
		free(p);
		free(vw);
		free(va);
		if(flag==1){
			free(v);
		}
		*/
		return ans;
	}
	return 0;
}

int findmedian(int v[],int L){
	return findk(v,L,(L-1)/2);
}
void quicksort(int v[],int l,int u){ //Sort elements in range [l,u)
	//printf("%d %d\n",l,u);
	if(u-l<=1){
		return;
	}else if(u-l==2){
		if(v[l]>v[l+1]){
			v[l]=v[l]+v[l+1];
			v[l+1]=v[l]-v[l+1];
			v[l]=v[l]-v[l+1];
			//swap(&v[l],&v[l+1]);
		}
		return;
	}else if(u-l>2){
		int vv[u-l];
		for(int i=l;i<u;i++){
			vv[i-l]=v[i];
		}
		int m=findmedian(vv,u-l);
		//free(vv);
		//int L=v.size();
		m+=l;
		int k=partition(v,l,u,m);
		/*
		for(auto a:v){
			cout<<a<<" ";
		}
		cout<<endl;
		*/
		quicksort(v,l,k);
		quicksort(v,k+1,u);
	}
}

int main(){
	/*
	srand(1);
	for(int j=0;j<100;j++){
		int n=rand()%100;
		int v1[n];
		int v2[n];
		for(int i=0;i<n;i++){
			int x=rand()%1000;
			v1[i]=x;
			v2[i]=x;
		}
		quicksort(v1,0,n);
		qsort(v2,n,sizeof(int),f1);
		for(int i=0;i<n;i++){
			if(v1[i]!=v2[i]){
				printf("Something went wrong\n");
				return 0;
			}
			if(i==n-1){
				printf("All Fine\n");
			}
		}
		//free(v1);
		//free(v2);
	}
	*/
	///*
	int n;
	scanf("%d",&n);
	int v[n];
	for(int i=0;i<n;i++){
		scanf("%d",v+i);;
	}
	quicksort(v,0,n);
	for(int i=0;i<n;i++){
		printf("%d ",v[i]);
	}
	//*/
	/*
	srand(1);
	for(int j=0;j<100;j++){
		int n=rand()%100;
		int v1[n];
		int v2[n];
		for(int i=0;i<n;i++){
			int x=rand()%1000;
			v1[i]=x;
			v2[i]=x;
		}
		qsort(v2,n,sizeof(int),f1);
		for(int i=0;i<n;i++){
			if(v1[findk(v1,n,i)]!=v2[i]){
				printf("Something went wrong\n");
				return 0;
			}
			if(i==n-1){
				printf("All Fine\n");
			}
		}
		//free(v1);
		//free(v2);
	}
	*/
	return 0;
}