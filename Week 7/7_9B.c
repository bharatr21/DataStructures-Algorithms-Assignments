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
	struct node* prev;
};

typedef struct node node;


int count(node* head)
{
	int ct=0;
	node* i = head;
	while(i)
	{
		i = i->next;
		ct++;
	}
	return ct;
}

void insert(node** h, int key)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data = key;
	temp->prev = NULL;
	temp->next = *h;
	if(*h) (*h)->prev = temp;
	(*h) = temp;
}

void printlist(node* head)
{
	node* i = head;
	while(i)
	{
		if(i->next) printf("%d->",i->data);
		else printf("%d->NULL\n",i->data);
		i = i->next;
	}
}

void inorder(node* root)
{
	if(!root) return;
	inorder(root->prev);
	printf("%d ",root->data);
	inorder(root->next);
}

void preorder(node* root)
{
	if(!root) return;
	printf("%d ",root->data);
	preorder(root->prev);
	preorder(root->next);
}

void postorder(node* root)
{
	if(!root) return;
	postorder(root->prev);
	postorder(root->next);
	printf("%d ",root->data);
}

node* sortedlistBST(node** h, int n)
{
	if(n <= 0) return NULL;
	node* left = sortedlistBST(h, n/2);
	node* root = *h;
	root->prev = left;
	*h = (*h)->next;
	root->next = sortedlistBST(h, n-n/2-1);
	return root;
}

int main()
{
	node* head = NULL;
	node** h = &head;
	insert(h, 8);
	insert(h, 7);
	insert(h, 6);
	insert(h, 5);
	insert(h, 4);
	insert(h, 3);
	insert(h, 2);
	insert(h, 1);
	int n = count(head);
	node* root = sortedlistBST(h, n);
	printf("Inorder Traversal:\n");
	inorder(root);
	printf("\n");
	printf("Preorder Traversal:\n");
	preorder(root);
	printf("\n");
	printf("Postorder Traversal:\n");
	postorder(root);
	printf("\n");
	return 0;
}
