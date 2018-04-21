#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)

int max(int a, int b) { return (a>b?a:b); }

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
	if(*h) {
		temp->next = *h;
		*h = temp;
	}
	else {
		*h = temp;
		temp->next = NULL;
	}
}

int getCount(node* h)
{
	int count=0;
	node* i = h;
	while(i)
	{
		count++;
		i = i->next;	
	}
	return count;
}

int getIntersection(int d, node* h1, node* h2)
{
	node* curr1 = h1;
	node* curr2 = h2;
	f(i,0,d)
	{
		if(!curr1) return -1;
		else curr1 = curr1->next;
	}
	while(curr1 && curr2)
	{
		if(curr1->data == curr2->data) {
			return curr1->data;
		}
		else {
			curr1 = curr1->next;
			curr2 = curr2->next;
		}
	}
	return -1;
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
	int n1, n2;
	scanf("%d",&n1);
	scanf("%d",&n2);
	int a[n1], b[n2];
	int c1, c2, d;
	node* head1=NULL;
	node** h1  = &head1;
	node* head2=NULL;
	node** h2  = &head2;
	f(i,0,n1) scanf("%d",&a[i]);
	fd(i,n1-1,0) insert(h1, a[i]);
	f(i,0,n2) scanf("%d",&b[i]);
	fd(i,n2-1,0) insert(h2, b[i]);
	c1 = getCount(head1);
	c2 = getCount(head2);
	printlist(h1);
	printlist(h2);
	if(c1 > c2) {
		d = c1 - c2;
		if(getIntersection(d, head1, head2)!=-1)
			printf("\n%d is the intersection point\n",getIntersection(d, head1, head2));
		else
			printf("\nNo intersection point\n");
	}
	else{
		d = c2 - c1;
		if(getIntersection(d, head2, head1)!=-1)
			printf("\n%d is the intersection point\n",getIntersection(d, head2, head1));
		else
			printf("\nNo intersection point\n");
	}
	return 0;
}