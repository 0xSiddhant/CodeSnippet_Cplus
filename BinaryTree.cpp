#include <iostream>
#include<queue>
#include<utility>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void print(node *root){
    if(root==NULL){
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

void printIn(node*root){
    if(root==NULL){
        return;
    }
    //Otherwise Left Root Right
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

void printPost(node*root){
    if(root==NULL){
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}

int height(node*root){
    if(root==NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs) + 1;

}

void printKthLevel(node*root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
    return;

}

void printAllLevels(node*root){
    int H = height(root);

    for(int i=1;i<=H;i++){
        printKthLevel(root,i);
        cout<<endl;
    }
}

int count(node*root){
    if(root==NULL){
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

void bfs(node *root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* f = q.front();
        cout<<f->data<<",";
        q.pop();

        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
    return;
}

int diameter(node *root) {
    if(root == NULL) { return 0;}
    int h = height(root->left) + height(root->right);
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);

    return max(h,max(op1,op2));
}

pair<int,int> fastDiameter(node* root) {
    pair<int, int> p;
    if(root == NULL) {
        p.first = p.second = 0;
        return p;
    }

    pair<int, int> p1 = fastDiameter(root->left);
    pair<int, int> p2 = fastDiameter(root->right);

    p.first = max(p1.first, p2.first) + 1;
    p.second = max(p1.first + p2.first, max(p1.second, p2.second));
    return p;
}

int sumReplacement(node * root) {
    if(root == NULL) { return 0;}
    if(root->left == NULL && root->right == NULL) {
        return root->data;
    }
    int l = sumReplacement(root->left);
    int r = sumReplacement(root->right);
    int temp = root->data;
    root->data = l + r;
    return root->data + temp;

}

pair<int,bool> checkBalanceHeight(node * root) {
    pair<int,bool> p;
    if(root == NULL) {
        p.first = 0;
        p.second = true;
        return p;
    }

    pair<int, bool> p1 = checkBalanceHeight(root->left);
    pair<int, bool> p2 = checkBalanceHeight(root->right);

    p.first = max(p1.first, p2.first) + 1;
    if(abs(p1.first+p2.first)<=1 && p1.second && p2.second) {
        p.second = true;
    } else {
        p.second = false;
    }
    return p;
}

int main(){ 
    node* root = buildTree();
    print(root);
    cout<<endl;

    printIn(root);
    cout<<endl;
    printPost(root);


    cout<<count(root)<<endl;
    printAllLevels(root);
    bfs(root);
    cout<<endl;
    cout<<diameter(root)<<endl;
    cout<<fastDiameter(root).second<<endl;
    cout<<sumReplacement(root)<<endl;
    cout<<checkBalanceHeight(root).second<<endl;
return 0;
}
