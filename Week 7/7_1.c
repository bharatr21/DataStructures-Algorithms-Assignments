#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,b,a) for(ll i=b;i>=a;i--)
#define null -1

#define parent(i)  ((i)-1)>>1
#define left(i)  (((i)<<1)+1)
#define right(i) (((i)<<1)+(1<<1))

struct heap
{
    int mi;
    int* A;
    int size;
};

typedef struct heap heap;

void create(heap *h, int type, int cap)
{
    h->mi = type;
    h->A = malloc(cap*sizeof(int));
    h->size = 0;
}

void swap(int* x, int* y)
{
    int temp = *x;
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
        if(l < h->size && h->A[l] < h->A[idx]) smallest = l;
        else smallest=idx;
        if(r < h->size && h->A[r] < h->A[smallest]) smallest = r;
        if(smallest!=idx) {
            swap(&(h->A[idx]), &(h->A[smallest]));
            heapify(h, smallest);
        }
    }
    else
    {
        if(l < h->size && h->A[l] > h->A[idx]) largest=l;
        else largest=idx;
        if(r < h->size && h->A[r] > h->A[largest]) largest=r;
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

void push(heap *h, int key) 
{

    int idx = h->size;
    h->A[h->size] = key;
    h->size++;
    if(h->mi)
    {
        while((idx > 0) && (h->A[idx] < h->A[parent(idx)]) )
        {
            swap(&h->A[idx], &h->A[parent(idx)]);
            idx = parent(idx);
        }
    }
    else
    {
        while((idx > 0) && (h->A[idx] > h->A[parent(idx)]) )
        {
            swap(&(h->A[idx]), &(h->A[parent(idx)]));
            idx = parent(idx);
        }
    }
}

int top(heap *h)
{
    return h->A[0];
}

void pop(heap *h)
{
    h->A[0] = h->A[h->size-1];
    h->size--;
    heapify(h, 0);
}

void printh(heap *h)
{
    int i;
    f(i,0,h->size) printf("%d ",h->A[i]);
    printf("\n");
}

int main()
{
    heap mih, mah;
    int t, n;
    double mid;
    create(&mih, 1, n);
    create(&mah, 0, n);
    scanf("%d",&n);
    printf("\n");
    f(i,0,n)
    {
    	scanf("%d",&t);
    	if(mah.size > mih.size)
    	{
    		if(t < mid)
    		{
    			push(&mih, top(&mah));
    			pop(&mah);
    			push(&mah, t);
    		}
    		else {
    			push(&mih, t);
    		}
    		mid = ((float)top(&mah)+top(&mih))/2.0;
    	}
    	else if(mah.size == mih.size)
    	{
    		if(t < mid)
    		{
    			push(&mah, t);
    			mid = top(&mah);
    		}
    		else
    		{
    			push(&mih, t);
    			mid = top(&mih);
    		}

    	}
    	else
    	{
    		if(t > mid)
    		{
    			push(&mah, top(&mih));
    			pop(&mih);
    			push(&mih, t);
    		}
    		else
    		{
    			push(&mah, t);
    		}
    		mid = ((float)top(&mah)+top(&mih))/2.0;
    	}
    	printf("%.1f\n",mid);
    }
    return 0;
}
