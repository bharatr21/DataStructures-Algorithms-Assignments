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

void insbeg(node** h, int key) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = key;
    temp->next=*h;
    temp->prev=NULL;
    if(*h) {
        (*h)->prev = temp;
    }
    *h = temp;
}

void insend(node** h, int key) {
    node* temp = malloc(sizeof(node));
    node* last = *h;
    temp->data = key;
    temp->next = NULL;
    if(!(*h)) {
        temp->prev = NULL;
        *h = temp;
        return;
    }
    while(last->next)
        last = last->next;
    last->next = temp;
    temp->prev = last;
    return;
}

void delpos(node** h, int i) {
    if(*h) return;
    int ct=0;
    node* last = *h;
    if(!i) *h = last->next;
    while((ct<i)&&(last->next)) {
        ct++;
        last = last->next;
    }
    if(last->next) {
        last->next->prev = last->prev;
    }
    if(last->prev) {
        last->prev->next = last->next;
    }
    free(last);
    return;
}

void delfirst(node** h) {
    node* last = *h;
    if(*h)
        *h = last->next;
    free(last);
    return;
}

void dellast(node** h) {
    node* last = *h;
    while(last->next)
        last = last->next;
    free(last);
    return;
}

void printlist(node** h) {
    node* i = *h;
    printf("Forward Traversal\n");
    while(i) {
        printf("%d->",i->data);
        i=i->next;
    }
    printf("Backward Traversal\n");
    while(i) {
        printf("<-%d",i->data);
        i=i->prev;
    }
}

int main()
{
    char ch;
    do {
        printf("Enter a choice \n a.Insert at Beginning\n b.Insert at end \n c. Remove ith element \n d. Remove first element \n e. Remove last element \nf. Print list \ng. Exit\n");
        scanf("%c",&ch);
        node* head = NULL;
        node**  h = &head;
        int i, key;
        switch(ch) {
            case 'a': {printf("Enter key: "); scanf("%d",&key); insbeg(h, key); break;}
            case 'b': {printf("Enter key: "); scanf("%d",&key); insend(h, key); break;}
            case 'c': {printf("Enter i: "); scanf("%d",&i); delpos(h, i); break;}
            case 'd': {delfirst(h); break;}
            case 'e': {dellast(h); break;}
            case 'f': {printlist(h); break;}
        };
    } while(ch!='g');
    return 0;
}
    