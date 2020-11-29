#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> v;
    bool isMinHeap;

    bool compare(int a, int b) {
        return isMinHeap ? a < b : a > b;
    }

    void heapify(int indx) {
        int left = 2 * indx;
        int right = left + 1;
        int minIndx = indx, last = v.size() - 1;

        if (left <= last and compare(v[left], v[indx])) {
            minIndx = left;
        }
        if (right <= last and compare(v[right], v[minIndx])) {
            minIndx = right;
        }
        if( minIndx != indx ) {
            swap(v[indx], v[minIndx]);
            heapify(minIndx);
        }
    }
public:
    Heap(int default_size = 10, bool type = false) {
        v.reserve(default_size);
        v.push_back(-1);
        isMinHeap = type;
    }

    void push(const int data) {
        v.push_back(data);
        int idx = v.size() - 1;
        int parent = idx/2;
        
        while(idx > 1 and compare(v[idx], v[parent])) {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }

    int top() const {
        return v[1];
    }

    void pop() {
        int last = v.size() - 1;
        swap(v[1], v[last]);
        v.pop_back();
        heapify(1);
    }

    bool empty() {
        return v.size() == 1;
    }
};


int main() {
    Heap h;
    int n;
    cin >>n;
    
    for( int i = 1;i<= n ;i++) {
        int no;
        cin >>no;
        h.push(no);
    }
    while(!h.empty()) {
        cout<<h.top()<< " ";
        h.pop();
    }
    return 0;
}
