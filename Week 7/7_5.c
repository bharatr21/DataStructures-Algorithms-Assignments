#include <stdio.h>
#include <stdlib.h>
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

node* merge(node* a, node* b);
void split(node* s, node** head, node** tail);

void insert(node** h, int key)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data = key;
	if(*h) {
		temp->next = *h;
		*h = temp;
	}
	else {
		*h = temp;
		temp->next = NULL;
	}
}

void mergesort(node** h)
{
	node* head = *h;
	node* a=NULL;
	node* b=NULL;
	if((!head)||(!head->next))
		return;
	split(*h, &a, &b);
	mergesort(&a);
	mergesort(&b);
	*h = merge(a,b);
}

void split(node* s, node** head, node** tail)
{
	node* slo=NULL;
	node* fast=NULL;
	if((!s)||(!s->next))
		return;
	else
	{
		slo = s;
		fast = s->next;
		while(fast)
		{
			fast = fast->next;
			if(fast)
			{
				slo = slo->next;
				fast = fast->next;
			}
		}
		*head = s;
		*tail = slo->next;
		slo->next = NULL;
	}
}

node* merge(node* a, node* b)
{
	node* result = NULL;
	if(!a)
		result = b;
	else if(!b)
		result = a;
	else if(a->data <= b->data)
	{
		result = a;
		result->next = merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge(a, b->next);
	}
	return result;
}

void printlist(node** h)
{
	node* i = *h;
	while(i)
	{
		if(i->next) printf("%d->",i->data);
		else printf("%d->NULL\n",i->data);
		i = i->next;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	f(i,0,n) scanf("%d",&a[i]);
	printf("\n");
	node* head =NULL;
	node** h = &head;
	fd(i,n-1,0) { insert(h, a[i]); }
	printlist(h);
	mergesort(h);
	printlist(h);
	return 0;
}