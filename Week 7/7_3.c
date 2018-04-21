#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define null -1

#define parent(i)  ((i)-1)>>1
#define left(i)  (((i)<<1)+1)
#define right(i) (((i)<<1)+(1<<1))

struct harr
{
	int el;
	int idx;
	int next;
};

typedef struct harr harr;

struct heap
{
    int mi;
    harr* A;
    int size;
};

typedef struct heap heap;


void create(heap *h, int type, int cap)
{
    h->mi = type;
    h->A = malloc(cap*sizeof(harr));
    h->size = 0;
}

void swap(harr* x, harr* y)
{
    harr temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(heap *h, int idx)
{
    int l,r, smallest, largest;
    l = left(idx);
    r = right(idx);
    if(h->mi)
    {
        if(l < h->size && h->A[l].el < h->A[idx].el) smallest = l;
        else smallest=idx;
        if(r < h->size && h->A[r].el < h->A[smallest].el) smallest = r;
        if(smallest!=idx) {
            swap(&(h->A[idx]), &(h->A[smallest]));
            heapify(h, smallest);
        }
    }
    else
    {
        if(l < h->size && h->A[l].el > h->A[idx].el) largest=l;
        else largest=idx;
        if(r < h->size && h->A[r].el > h->A[largest].el) largest=r;
        if(largest!=idx) {
            swap(&(h->A[idx]), &(h->A[largest]));
            heapify(h, largest);
        }
    }
}

void buildheap(heap *h)
{
    fd(i,h->size/2,0) {
        heapify(h, i);
    }
}

void push(heap *h, harr key) 
{

    int idx = h->size;
    h->A[h->size] = key;
    h->size++;
    if(h->mi)
    {
        while((idx > 0) && (h->A[idx].el < h->A[parent(idx)].el) )
        {
            swap(&h->A[idx], &h->A[parent(idx)]);
            idx = parent(idx);
        }
    }
    else
    {
        while((idx > 0) && (h->A[idx].el > h->A[parent(idx)].el) )
        {
            swap(&(h->A[idx]), &(h->A[parent(idx)]));
            idx = parent(idx);
        }
    }
}

harr top(heap *h)
{
    return h->A[0];
}

void pop(heap *h)
{
    h->A[0] = h->A[h->size-1];
    h->size--;
    heapify(h, 0);
}

// void printh(heap *h)
// {
//     int i;
//     f(i,0,h->size) printf("%d ",h->A[i]);
//     printf("\n");
// }

int main()
{
    heap mh;
    int n,k;
    scanf("%d %d", &n, &k);
    create(&mh, 1, n);
    int a[n][k], res[n*k];
    harr h[n];
    f(i,0,n)
    {
    	f(j,0,k)
    	{
    		scanf("%d", &a[i][j]);
    	}
    }
    f(i,0,n)
    {
    	h[i].el = a[i][0];
    	h[i].idx = i;
    	h[i].next = 1;
    	push(&mh, h[i]);
    }
    f(i,0,n*k)
    {
    	harr root = top(&mh);
    	pop(&mh);
    	res[i] = root.el;
    	if(root.next < n)
    	{
    		root.el = a[root.idx][root.next];
    		root.next++;
    		push(&mh, root);
    	}
    	else root.el = 1000001;
    }
    f(i,0,n*k) printf("%d ",res[i]);
    printf("\n");
    return 0;
}
