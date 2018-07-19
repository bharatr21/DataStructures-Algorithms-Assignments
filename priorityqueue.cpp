#include <bits/stdc++.h>
#define parent(i) ((i)-1) >> 1
#define left(i) ((i) << 1) + 1
#define right(i) ((i)+1) << 1
using namespace std;

template<typename T>
class pq
{
    vector<T> heap;
    long long size;
    bool type; //True/1 denotes Min Heap, False/0 denotes Max Heap
    void heapifyDown(long long idx);
    void heapifyUp(long long idx);
    void buildheap();
public:
	pq();
    pq(bool typ);
    void createheap(bool typ);
    void push(T key);
    T top();
    void pop();
    void printh();
};

template<typename T>
pq<T>::pq(bool typ)
{
    type = typ;
    size = 0;
}

template<typename T>
pq<T>::pq()
{
    type = true; //Min Heap by Default
    size = 0;
}

template<typename T>
void pq<T>::heapifyDown(long long idx)
{
    long long l, r, smallest, largest;
    l = left(idx);
    r = right(idx);
    if(type)
    {
        if(l < size && heap[l] < heap[idx]) smallest = l;
        else smallest = idx;
        if(r < size && heap[r] < heap[smallest]) smallest = r;
        if(smallest != idx)
        {
            swap(heap[idx], heap[smallest]);
            heapifyDown(smallest);
        }
    }
    else
    {
        if(l < size && heap[l] > heap[idx]) largest = l;
        else largest = idx;
        if(r < size && heap[r] > heap[largest]) largest = r;
        if(largest != idx)
        {
            swap(heap[idx], heap[largest]);
            heapifyDown(largest);
        }
    }
}

template<typename T>
void pq<T>::heapifyUp(long long idx)
{
    long long p;
    if(type)
    {
        p = parent(idx);
        while(idx > 0 && heap[idx] < heap[p])
        {
            swap(heap[idx] , heap[p]);
            idx = parent(idx);
            p = parent(idx);
        }
    }
    else
    {
        p = parent(idx);
        while(idx > 0 && heap[idx] > heap[p])
        {
            swap(heap[idx] , heap[p]);
            idx = parent(idx);
            p = parent(idx);
        }
    }
}

template<typename T>
void pq<T>::buildheap()
{
	long long i;
    for(i = size/2; i>=0 ; i--)
    {
        heapifyDown(i);
    }
}

template<typename T>
void pq<T>::createheap(bool typ)
{
    type = typ;
    size = 0;
}

template<typename T>
void pq<T>::push(T key)
{
    long long idx = size;
    heap.push_back(key);
    size++;
    heapifyUp(idx);
}

template<typename T>
T pq<T>::top()
{
    return heap[0];
}

template<typename T>
void pq<T>::pop()
{
    heap[0] = heap[size - 1];
    heap.pop_back();
    size--;
    heapifyDown(0);
}

template<typename T>
void pq<T>::printh()
{
    for(T i:heap) cout << i << ' ';
    cout << '\n';
}

//Some Basic Testing
int main()
{
	pq<char> mh;
	pq<string> maxh;
	mh.createheap(1); //Min Heap
	maxh.createheap(0); //Max Heap
	mh.push('A');
	mh.printh();
	mh.push('A');
	mh.printh();
	mh.push('B');
	mh.printh();
	mh.push('C');
	mh.printh();
	mh.push('D');
	mh.printh();
	cout << mh.top() << '\n';
	mh.printh();
	mh.pop();
	mh.printh();
	mh.pop();
	mh.printh();
	mh.pop();
	mh.printh();
    return 0;
}