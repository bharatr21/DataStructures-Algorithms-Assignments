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

node* gtail(node* cur)
{
	while(cur && cur->next)
		cur = cur->next;
	return cur;
}

node* partition(node* head, node* end, node** nhead, node** nend)
{
	node *pivot = end;
	node *prev = NULL, *cur = head, *tail = pivot;
	while(cur != pivot)
	{
		if(cur->data < pivot->data)
		{
			if(*nhead == NULL) *nhead = cur;
			prev = cur;
			cur = cur->next;
		}
		else
		{
			if(prev)
				prev->next = cur->next;
			node* temp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = temp;
		}
	}
	if(!(*nhead))
		*nhead = pivot;
	*nend = tail;
	return pivot;
}

node* qusort(node* head, node* end)
{
	if(!head||head == end) return head;
	node* nhead = NULL, *nend = NULL;
	node* pivot = partition(head, end, &nhead, &nend);
	if(nhead!=pivot)
	{
		node* temp = nhead;
		while(temp->next != pivot)
			temp = temp->next;
		temp->next = NULL;
		nhead = qusort(nhead, temp);
		temp = gtail(nhead);
		temp->next = pivot;
	}
	pivot->next = qusort(pivot->next, nend);
	return nhead;
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
	insert(h, 5);
	insert(h, 20);
	insert(h, 4);
	insert(h, 3);
	insert(h, 30);
	*h = qusort(*h, gtail(*h));
	printlist(h);
	del(h, 4);
	printlist(h);
	*h = qusort(*h, gtail(*h));
	printlist(h);
	return 0;
}
