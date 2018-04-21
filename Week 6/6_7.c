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

void reverse1(node** h) {
	node* prev = NULL;
	node* curr = *h;
	node* next = NULL;
	while(curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*h = prev;
}

void reverse2(node** h) {
	if(*h) {
		node* first = *h;
		node* rest = first->next;
		if(rest) {
			reverse2(&rest);
			first->next->next = first;
			first->next = NULL;
			*h = rest;
		}
		else
			return;
	}
	else
		return;
}

void printlist(node* head) {
	node* i = head;
	if(!i) printf("NULL\n");
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
	insert(h,7);
	insert(h,6);
	insert(h,5);
	insert(h,4);
	insert(h,3);
	insert(h,2);
	insert(h,1);
	printlist(head);
	reverse1(h);
	// reverse2(h);
	printlist(head);
	return 0;
}
