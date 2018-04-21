#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

struct S
{
    int a[1000];
    int top;
}st1, st2;

typedef struct S s;

void enqueue(int key) {
    if(st1.top == 999) { printf("Queue Overflow\n"); return; }
    else {
        st1.top++;
        st1.a[st1.top]=key;
    }
}

void dequeue() {
    if(st1.top==-1&&st2.top==-1) {printf("Queue Underflow\n"); return; }
    else {
        if(st2.top==-1) {
            while(st1.top!=-1) {
                ++st2.top;
                st2.a[st2.top] = st1.a[st1.top];
                st1.top--;
            }
        }
        printf("%d\n",st2.a[st2.top]);
        st2.top--;
    }
}

void printst(s* st) {
    fd(i, st->top, 0) {
        printf("%d ",(*st).a[i]);
    }
    printf("\n");
}

int main()
{
    st1.top=-1, st2.top=-1;
    int key;
    char ch;
    do {
        printf("Enter a choice\na. Enqueue\nb. Dequeue\nc. Print stack1\nd. Print stack2\ne. Exit\n");
        scanf("%c",&ch);
        switch(ch) {
            case 'a': {printf("Enter key: "); scanf("%d",&key); enqueue(key); break;}
            case 'b':{dequeue(); break;}
            case 'c':{printst(&st1); break;}
            case 'd':{printst(&st2); break;}
        };
    }while(ch!='e');
    return 0;
}
