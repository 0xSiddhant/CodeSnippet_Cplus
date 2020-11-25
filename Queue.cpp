#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int cs,ms,f,r;

    public:
    Queue(int size = 5) {
        arr = new int[size];
        cs = 0;
        ms = size;
        f= 0;
        r = ms-1;
    }

    bool full() const { return cs == ms; }

    void push(const int data) {
        if(!full()) {
            r = (r + 1) % ms;
            arr[r] = data;
            cs++;
        }
    }

    bool empty() const { return cs == 0; }

    void pop() {
        if(!empty()) {
            f = (f + 1) % ms;
            cs--;
        }
    }

    int front() { return arr[f];}
    ~Queue() {
        if(arr != NULL) {
            delete [] arr;
            arr = NULL;
        }
        cout<<"Queue Destoryed"<<endl;
    }
};

int main() {
   
   Queue q(10);

   for(int i = 1;i<8;i++) {
       q.push(i);
   }

    q.pop();
    q.pop();

    while(!q.empty()) {
        cout<<q.front()<< " "<< endl;
        q.pop();
    }
}
