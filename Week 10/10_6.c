#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)

struct node
{
	char data;
	struct node* left;
	struct node* right;
};

typedef struct node node;

node* getnode(char key)
{
	node* temp = malloc(sizeof(node));
	temp->data = key;
	temp->right = temp->left = NULL;
	return temp;
}


int search(char a[], int st, int end, int key)
{
	int i;
	f(i,st,end + 1)
	{
		if(a[i] == key) break;
	}
	return i;
}

node* buildtree(char in[], char post[], int st, int end, int* pind)
{
	if(st > end) return NULL;
	node* nod = getnode(post[*pind]);
	nod->left = nod->right = NULL;
	(*pind)--;
	if(st == end) return nod;
	int idx = search(in, st, end, nod->data);
	nod->right = buildtree(in, post, idx + 1, end, pind);
	nod->left = buildtree(in, post, st, idx - 1, pind);
	return nod;
}

void preorder(node* root)
{
	if(!root) return;
	printf("%c",root->data);
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	char s[100];
	scanf("%s",s);
	int n = strlen(s);
	int i;
	char in[n], post[n];
	f(i,0,n) in[i] = s[i];
	f(i,0,n) s[i] = '#';
	// getchar();
	scanf("%s",s);
	f(i,0,n) post[i] = s[i];
	int pind = n-1;
	node* root = buildtree(in, post, 0, n - 1, &pind);
	printf("Preorder: ");
	preorder(root);
	printf("\n");
	return 0;
}
