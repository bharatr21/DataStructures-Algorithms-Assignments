#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

struct node
{
	int data;
	struct node* next;	
};

typedef struct node node;

void insert(node** h, int key)
{
	node* temp = malloc(sizeof(node));
	temp->data = key;
	if(*h)
	{
		temp->next = *h;
		temp = *h;
	}
	else
	{
		temp->next = NULL;
		*h = temp;
	}
}

int search(node** h, int key)
{
	node* i = *h;
	int ct = 0;
	while((i) && (i->data !=key))
	{
		ct++;
		i = i->next;
	}
	return ct;
}

void printh(node** h)
{
	node* i = *h;
	while(i)
	{
		if(i->next) printf("%d->\n",i->data);
		else printf("%d->NULL\n",i->data);
		i = i->next;
	}
	printf("\n");
}

int main()
{
	int m, n;
	int x = 50;
	scanf("%d%d",&m,&n);
	node* head[m];
	f(i,0,m)
	{
		head[i] = 0;
	}
	srand(time(0));
	f(i,0,n)
	{
		int j = rand();
		int idx = j%m;
		insert(&head[idx], j);
	}
	f(i,0,m)
	{
		printh(&head[i]);
	}
	int ct = 0;
	f(i,0,x)
	{
		int k = rand();
		ct += search(&head[k%m], k);
	}
	printf("Average case for %d elems: %f\n",x,(ct*1.0)/x);
	return 0;
}
