#include <iostream>
using namespace std;

class Node {
    public:
    int n;
    Node* next;

    Node(int n) {
        this->n = n;
        next = NULL;
    }
};

int getLength(Node *head) {
   int count = 0;
   while(head != NULL) {
       count++;
       head = head -> next;
   } 
   return count;
}

void insertHead(Node* &head, int data) {
    if(head == NULL) {
        head = new Node(data);
        return;
    }
    Node * n = new Node(data);
    n->next = head;
    head = n;
}

void insertLast(Node* &head,int data) {
    if(head == NULL) {
        insertHead(head,data);
        return;
    }
    Node *temp = head;
    while(temp->next != NULL) {
        temp  = temp->next;
    }
    Node * n = new Node(data);
    temp->next = n;
}

void insertAt(Node* &head, int data,int pos) {
    if(head == NULL or pos == 0) {
        insertHead(head, data);
    } else if( pos > getLength(head)) {
        insertLast(head,data);
    } else {
        Node *temp = head;
        for(int i=1;i<=pos-1;i++) {
            temp = temp->next;
        }
        Node *n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

void deleteHead(Node* &head) {
    if(head == NULL) {
        return;
    }
    Node *temp = head->next;
    delete head;
    head = temp;
}

void deleteLast(Node* &head) {
    if(head == NULL) {
        return;
    }
    Node *n = head;
    while(n->next->next != NULL) {
        n = n->next;
    }
    Node *temp = n->next;
    n->next = NULL;
    delete temp;
}

bool search(Node*head,int key) {
    if(head == NULL) { return false;}
    while(head->next != NULL) {
        if(head->n == key) { return true;}
        head = head->next;
    }
    return false;
}

bool searchRecusively(Node*head,int key) {
    if(head == NULL) { return false; }
    if(head->n == key) { return true;}
    return searchRecusively(head->next, key);
}
void print(Node* head) {
    while(head != NULL) {
        cout<<head->n<<" ";
        head = head->next;
    }
    cout<<endl;
}

void reverse(Node* &head) {
    Node* C = head;
    Node* P = NULL;
    Node* N;

    while(C!= NULL) {
        //save the next node
        N = C->next;
        //make the current node pointer to prev
        C->next = P;
        //Update the Prev & C take one step further
        P=C;
        C=N;
    }
    head = P;
}

Node* recReverse(Node* head) {
    if(head == NULL or head->next == NULL) { return head;}

    Node* shead = recReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return shead;
}

int kthJump(Node*node,int k) {
    Node *fast = node;
    Node *slow = node;
    while(k--) {
        fast = fast ->next;
    }
    while(fast!=NULL) {
        fast=fast->next;
        slow = slow ->next;
    }
    return slow->n;
}
ostream& operator<<(ostream &o,Node *head) {
    print(head);
    return o;
}

void rotateCWBy(Node* &head,int n) {
    if(head == NULL or n<=0) { return;}
    int size = getLength(head);
    n = n % size;
    if (n == 0) { return; }
    Node * temp = head;
    Node *node = head;
    for(int i =1;i<size -n;i++) {
        temp = temp->next;
    }
    Node *r = temp->next;
    head = r;
    temp->next = NULL;
    while(r->next != NULL) { r = r->next;}
    r->next = node;
}

void rotateACWBy(Node *&head,int n) {
    // reverse(head);
    // rotateCWBy(head,n);
    // reverse(head);
    if(head == NULL or n<=0) { return;}
    int size = getLength(head);
    n = n % size;
    if (n == 0) { return; }
    Node * temp = head;
    Node *node = head;
    for(int i =1;i<n;i++) {
        temp = temp->next;
    }
    head=temp->next;
    temp->next = NULL;
    Node *r = head;
    while(r->next != NULL) { r = r->next;}
    r->next = node;
}
int main() {
    Node *head= NULL;
    insertLast(head,12);
    insertHead(head,3);
    insertHead(head,4);
    insertHead(head,1);
    insertHead(head,6);
    insertLast(head,2);
    insertAt(head,5,4);
    print(head);

    deleteHead(head);
    deleteLast(head);
    insertLast(head, 00);
    cout<<head;
    cout<<search(head,12);
    cout<<searchRecusively(head,12);
    reverse(head);
    cout<<head;
    head = recReverse(head);
    insertLast(head,7);
    cout<<head;
    // cout<<kthJump(head,3);
    // rotateCWBy(head,1);
    cout<<endl;
    rotateACWBy(head,3);
    cout<<head;
    return 0;
}
