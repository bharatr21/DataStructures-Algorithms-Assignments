#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'
#define SZ 10

void insert(int* hash, int key)
{
	int i = 1, idx;
	idx = key%10;
	if(hash[idx] == -1 || hash[idx] == 0) hash[idx] = key;
	else
	{
		while(hash[idx] != -1)
		{
			idx = (idx + (i*i)) % SZ;
			i++;
		}
		hash[idx] = key;
	}
}

int search(int* hash, int key)
{
	int idx = key%10, i = 1;
	while((hash[idx] != key) && (hash[idx] != -1) && (i<=10))
	{
		idx = (idx + (i*i)) % SZ;
		i++;
	}
	if((hash[idx] == -1)||(i>=11)) return -1;
	else return idx;
}

void delete(int* hash, int key)
{
	int idx = search(hash, key);
	if(idx == -1) return;
	else hash[idx] = 0;
}

void printh(int* hash)
{
	f(i,0,SZ) printf("%d ",hash[i]);
	printf("\n");
}


int main()
{
	int hash[10], a[10], n=9;
	memset(hash, -1, sizeof(hash));

	//Testing hash table operations
	f(i,0,n) scanf("%d",&a[i]);
	f(i,0,n) insert(hash, a[i]);
	printf("\n");
	printh(hash);
	/*printf("%d\n",search(hash, 43));
	delete(hash, 99);
	delete(hash, 43);
	printf("\n");
	printh(hash);
	delete(hash, 73);
	delete(hash, 72);
	printf("\n");
	printh(hash);
	*/
	return 0;
}
