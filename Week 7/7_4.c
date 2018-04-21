#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node node;

node* append(node* leftlist, node* rightlist)
{
	if(!leftlist)
		return rightlist;
	if(!rightlist)
		return leftlist;
	node* leftlast = leftlist->left;
	node* rightlast = rightlist->left;
	leftlast->right = rightlist;
	rightlist->left = leftlast;

	leftlist->left  = rightlast;

	rightlast->right = leftlist;

	return leftlist;
}

node* convertTreetoList(node* root)
{
	if(!root) return NULL;
	node* left = convertTreetoList(root->left);
	node* right = convertTreetoList(root->right);

	root->left = root->right = root;

	return append(append(left, root), right);
}

node* insert(int data)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void traverse(node* head)
{
	printf("Circular Linked List is :\n");
	node* i = head;
	do
	{
		if(head!=i->right) printf("%d->", i->data);
		else printf("%d",i->data);
		i = i->right;
	} while(head!=i);
	printf("\n");
}

int main()
{
	node* root = insert(4);
    root->left = insert(2);
    root->right = insert(6);
    root->left->left = insert(1);
    root->left->right = insert(3);
    root->right->left = insert(5);
    root->right->right = insert(7);

    node* head = convertTreetoList(root);
    traverse(head);
	return 0;
}
