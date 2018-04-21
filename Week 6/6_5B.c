#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define nl '\n'

struct Q
{
    int a[1000];
    int front, rear;
}q1, q2;

typedef struct Q q;


void swap(q** q1, q** q2) {
    q* qu = *q1;
    *q1 = *q2;
    *q2 = qu;
}


void push(int key) {
    if(q1.rear == 999) { printf("Queue Overflow\n"); return; }
    else {
        if(q1.rear==-1) q1.front++;
        q1.rear++;
        q1.a[q1.rear]=key;
    }
}

void pop() {
    if(q1.front == q1.rear) {
        printf("Queue Underflow\n"); 
        q1.front = q1.rear = -1;
}
    else {
            while(q1.front!=q1.rear) {
                ++q2.rear;
                q2.a[q2.rear] = q1.a[q1.front];
                q1.front++;
            }
        printf("%d\n",q1.a[q1.front]);
        q1.front++;
        q** qtt1 = &q1;
        q** qtt2 = &q2;
        swap(qtt1,qtt2);
    }
}

void printq(q* qu) {
    f(i, qu->front+1, qu->rear+1) {
        printf("%d ",(*qu).a[i]);
    }
    printf("\n");
}

int main()
{
    q1.front = -1;
    q1.rear = -1;
    q2.front = -1;
    q2.rear = -1;
    int key;
    char ch;
    do {
        printf("Enter a choice\na. Push\nb. Pop\nc. Print queue1\nd. Print queue2\ne. Exit\n");
        scanf("%c",&ch);
        switch(ch) {
            case 'a': {printf("Enter key: "); scanf("%d",&key); push(key); break;}
            case 'b':{pop(); break;}
            case 'c':{printq(&q1); break;}
            case 'd':{printq(&q2); break;}
            default: break;
        };
    }while(ch!='e');
    return 0;
}