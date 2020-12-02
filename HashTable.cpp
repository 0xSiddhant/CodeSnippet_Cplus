#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    string key;
    T value;
    Node<T> *next;

    Node(string key, T value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~Node() {
        cout<<"Destory "<<key<<"  ====="<<endl;
        if (next != NULL) {
            delete next; // Recursive Destructor to avoid MEMORY LEAK
        }
    }
};

template<typename T>
class HashTable {
    Node<T> **table; // pointer to array of pointer
    int table_size;
    int current_size;

    int hashFunc(string key) {
        int idx = 0;
        int p = 1;
        for(int j =0;j<key.length();j++) {
            idx = idx + (key[j]*p)%table_size;
            idx = idx % table_size;
            p = (p*27)%table_size;
            //taking mode at each step to prevent from larger power overflow which gives -ve value and cause segmentation fault
        }
        return idx;
    }

    void rehash() {
        Node<T> **oldTable = table;
        int oldTableSize = table_size;
        table_size = 2*table_size+3;
        table = new Node<T>*[table_size];
        for(int i = 0;i<table_size;i++) {
            table[i] = NULL;
        }
        current_size = 0;
        for(int i=0;i<oldTableSize;i++) {
            Node<T>* temp = oldTable[i];
            while(temp != NULL) {
                insert(temp->key,temp->value);
                temp = temp->next;
            }
            if(oldTable[i] != NULL) {
                delete oldTable[i]; // call recursive destructor
            }
        }
        delete [] oldTable;
    }
public:
    HashTable(int ts=7) {
        table_size = ts;
        table = new Node<T>*[table_size];
        current_size = 0;
        for(int i=0;i<table_size;i++) {
            table[i] = NULL; // removing all garbage value
        }
    }

    void insert(string key, T value) {
        int idx = hashFunc(key);
        Node<T>*n = new Node<T>(key, value);
        // Insertion at the head of linked list
        n->next = table[idx];
        table[idx] = n; // insertion at head
        current_size++;

        //rehash
        float load_factor = current_size/(1.0*table_size);
        if(load_factor>0.75) {
            rehash();
        }
    }

    T* search(string key) {
        int idx = hashFunc(key);
        Node<T> *temp = table[idx];
        while(temp!=NULL) {
            if(temp->key == key) { return &temp->value; }
            temp = temp->next;
        }
        return NULL;
    }

    void erase(string key) {
        int idx = hashFunc(key);
        Node<T> *temp = table[idx];
        if(temp == NULL) { return; } 
        if(temp->key == key && temp->next == NULL) {
            table[idx] = NULL;
            delete temp;
            return;
        }
        if(temp->key == key) {
            Node<T>* head = temp->next;
            table[idx] = head;
            temp->next = NULL;
            delete temp;
            return;
        }
        if (temp->next == NULL) { return; }
        Node<T> * fast = temp->next;
        while(fast->key != key) {
            fast = fast->next;
            temp = temp->next;
        }
        if (fast->next != NULL) {
            temp->next = fast->next;
             fast->next = NULL;
        } else {
            temp->next = NULL;
        }
       delete fast;
    }

    T& operator[](string key) {
        T* f = search(key);
        if (f == NULL) {
            //Insert key, value(garbage) in the hashmap
            T garbage;
            insert(key,garbage);
            f = search(key);
        }
        return *f;
    }
    void print() {
        for(int i=0;i<table_size;i++) {
            cout<<"Bucket "<<i<<" ->:";
            Node<T> *n = table[i];
            while(n != NULL) {
                
                cout<<n->key<<" -> "<<n->value<<" ";
                n = n->next;
            }
            cout<<endl;
        }
    }
};
int main() {
    
    HashTable<int> price_menu;

    price_menu.insert("Burger",40);
    price_menu.insert("Pizza",70);
    price_menu.insert("Dosa",80);
    price_menu.insert("Ice Cream",139);
    price_menu.insert("Sandwich",23);
    price_menu.insert("Lassi",10);
    cout<<endl<<endl;
    price_menu.erase("Lassi");
    price_menu.print();
    // auto t = price_menu.search("Lassi");
    // if(t != NULL) {
    //     cout<<*t;
    // }
    cout<<price_menu["Pizza"];
    return 0;
}
