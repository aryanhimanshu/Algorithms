#include <iostream>
#define MAX_INT (1<<30)
#define MIN_INT (-(1<<30))

using namespace std;

class MinHeap {
    /**
        Binary Heaps have 3 main operations:
        1. Return element with highest priority
        2. Remove element with highest priority
        3. Insert element into the heap tree
		
		In MinHeap the highest priority is for the min element
    **/
public:
    /// Default Constructor
    MinHeap(int cap = 20) {
        h_size = 0;
        h_capacity = cap;
        h_items = new int[cap];
    }

    /// Destructor - delete allocated array to avoid memory leak
    ~MinHeap() {
        delete[] h_items;
    }

    /// 1. Return element with highest priority
    int getMin(){
        if(h_size <= 0)
            return MAX_INT;
        return h_items[0];
    }

    /// 2. Remove element with highest priority
    int extractMin(){
        if(h_size == 0){
            return MAX_INT;
        }
        if(h_size == 1){ // No "last node" to swap with
            h_size--;
            return h_items[0];
        }
        int root_val = h_items[0];
        /// Swap root with last item, then heapify down
        h_items[0] = h_items[--h_size];
        MinHeapify(0);
        return root_val;
    }


    /// 3. Insert element into the MinHeap: put new element at the end and heapify up
    void insertItem(int item) {
        if(h_size == h_capacity) {
            cout << "Overflow!\n";
            return;
        }
        h_items[h_size++] = item;
        int ind = h_size - 1;
        heapifyUp(h_size - 1); // Heapify up starting from the end of the tree
    }

    /// 4. Delete element with given index
    void deleteItem(int i){
        decreaseItem(i, MIN_INT);
        extractMin();
    }

    /// 5. Replace value of ith element with new_val (a smaller value)
    void decreaseItem(int i, int new_val){
        if(i <= 0 || i >= h_size || new_val >= h_items[i]) {
            return;
        }
        h_items[i] = new_val;
        heapifyUp(i); // Heapify up starting from the decreased element
    }

    /// HeapifyUp: Swap element with parent until no parent is greater than its child
    void heapifyUp(int i) {
        while(i != 0 && h_items[parent(i)] > h_items[i]) {
            swap(h_items[parent(i)], h_items[i]);
            i = parent(i);
        }
    }

    /// MinHeapify (or Heapify down): Swap item with the smallest child until there is no smaller child (recursive)
    void MinHeapify(int n) {
        int l = left(n);
        int r = right(n);
        int i_smallest = n;
        if(l < h_size && h_items[l] < h_items[n])
            i_smallest = l;
        if(r < h_size && h_items[r] < h_items[i_smallest])
            i_smallest = r;
        if(i_smallest != n){
            swap(h_items[n], h_items[i_smallest]);
            MinHeapify(i_smallest);
        }
    }

    // Helper functions
    int left(int i){ return 2*i+1; }
    int right(int i){ return 2*i + 2; }
    int parent(int i){ return (i-1)/2; }


private:

    int* h_items;
    int h_capacity;
    int h_size;
};





int main()
{
    return 0;
}
