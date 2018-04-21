#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	node* temp = (node*)malloc(sizeof(node));
	temp->data = key;
	if(*h)
	{
		temp->next = *h;
		*h = temp;
	}
	else
	{
		temp->next = NULL;
		*h = temp;
	}
}

void printlist(node** h)
{
	node* i  = *h;
	while(i)
	{
		if(i->next) printf("%d->",i->data);
		else printf("%d\n",i->data);
		i = i->next;
	}
}

int med(node** h)
{
	node* fast = *h;
	node* slo = *h;
	while(fast && fast->next)
	{
		fast=fast->next->next;
		slo = slo->next;
	}
	return slo->data;
}

void del(node** h, int key)
{
	node* head = *h;
	node* temp = head;
	node* prev = NULL;
	if(temp && temp->data == key)
	{
		head = temp->next;
		free(temp);
		return;
	}
	while(temp && temp->data!=key)
	{
		prev = temp;
		temp = temp->next;
	}
	if(temp == NULL) return;
	prev->next = temp->next;
	free(temp);
}

int main()
{
	node* head = NULL;
	node** h = &head;
	/*insert(h, 6);
	insert(h, 5);*/
	insert(h, 4);
	insert(h, 3);
	insert(h, 2);
	insert(h, 1);
	printlist(h);
	printf("%d\n",med(h));
	del(h, 4);
	printlist(h);
	printf("%d\n",med(h));
	return 0;
}
