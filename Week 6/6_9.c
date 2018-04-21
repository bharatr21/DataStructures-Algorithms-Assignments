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

void newnode(node** h, int key)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = key;
    if(*h) {
    	temp->next = *h;
    	*h = temp;
    }
    else {
    	*h = temp;
    	(*h)->next = NULL;
    	// printf("%d->",temp->data);
    }
}

int cycle(node** h) {
	node* slo = *h;
	node* fast = *h;
	while((slo)&&(fast)) 
	{
		slo=slo->next;
		fast=fast->next->next;
		if(slo==fast) return 1;
	}
	return 0;
}

void printlist(node** h) {
	node* i = *h;
	while(i){
		if(i->next) printf("%d->",i->data);
		else printf("%d\n",i->data);
		i=i->next;
	}
}

int main()
{
	node* head = NULL;
	node** h = &head;
	newnode(h,10);
	newnode(h,20);
	newnode(h,40);
	newnode(h,50);
	// head->next->next->next = head->next;
	printlist(h);
    printf("\n%d\n",cycle(h));
	return 0;
}
