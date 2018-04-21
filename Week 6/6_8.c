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

void swap(int* a, int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void insert(node** h, int key) {
	node* temp = (node*)malloc(sizeof(node));
	temp->data = key;
	if(*h) {
		temp->next = *h;
		*h =  temp;	
	}
	else {
		*h = temp;
		temp->next = NULL;
	}
}

void pairswap(node** h) {
	node* i = *h;
	while((i)&&(i->next)) {
		swap(&(i->data),&(i->next->data));
		i = (i->next)->next;
	}
}

void printlist(node* head) {
	node* i = head;
	while(i) {
		if(i->next) printf("%d->",i->data);
		else printf("%d->NULL\n",i->data);
		i = i->next;
	}	
}

int main()
{
	node* head=NULL;
	node** h = &head;
	insert(h,4);
	insert(h,3);
	insert(h,2);
	insert(h,1);
	printlist(head);
	pairswap(h);
	printlist(head);
	return 0;
}
