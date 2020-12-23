#include <iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    char data;
    unordered_map<char, Node*> children;
    bool terminal;

    Node(char c) {
        data = c;
        terminal = false;
    }
};

class Tries {
    Node* root;
    int cnt;

public:
    Tries() {
        root = new Node('\0');
        cnt = 0;
    }

    void insert(char *w) {
        Node *temp = root;
        for(int i=0; w[i] != '\0';i++) {
            char ch = w[i];
            if(temp->children.count(ch)) {
                temp = temp->children[ch];
            } else {
                Node *n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    bool find(char *w) {
        Node *temp = root;
        for(int i=0;w[i]!= '\0';i++) {
            char ch = w[i];
            if(temp->children.count(ch) == 0) {
                return false;
            } else {
                temp = temp->children[ch];
            }
        }
        return temp->terminal;
    }
};

int main() {
    Tries t;
    char arr[][10] = {"Hello", "No","Not", "BAC", "Try"};

    for(int i=0;i<5;i++) {
        t.insert(arr[i]);
    }

    if(t.find(arr[1])) {
        cout<<"Present"<<endl;
    } else {
        cout<<"Not Present"<<endl;
    }

    return 0;
}
