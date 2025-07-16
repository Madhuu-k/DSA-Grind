#include<iostream>
#include<vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int smallest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;

        if (left < heap.size() && heap[left] < heap[smallest]) smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest]) smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) return -1;
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minVal;
    }

    void printHeap() {
        cout << "Heap: ";
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;
    h.insert(10);
    h.insert(20);
    h.insert(3);
    h.insert(5);
    h.insert(1);
    h.printHeap();
    cout << "Min Element: " << h.extractMin() << endl;
    h.printHeap();
    return 0;
}