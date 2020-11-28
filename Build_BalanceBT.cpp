/*
You are given a sorted data of n integers. You have to form a balanced Binary Search Tree and then print preorder traversal of the tree.

Input Format
First line contains integer t as number of test cases.
Each test case contains following input. First line contains integer n which represents the length of the data and next line contains n space separated integers denoting the elements for the BST.

Constraints
1 < t < 100
1< n < 1000
*/
#include<iostream>
using namespace std;
int *arr = new int[1005];
class node {
	public:
	int data;
	node *left;
	node *right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree(node* root, int data) {
	if (root == NULL) {
		return new node(data);
	}
	if(root->data > data) {
		root->left = buildTree(root->left,data);
	} else {
		root->right = buildTree(root->right,data);
	}
	return root;
}

void printInOrder(node *root) {
	if (root == NULL) { return; }

    cout<<root->data<<" ";
	printInOrder(root->left);
	printInOrder(root->right);
}

node* balanceBTree(node *root,int s, int e) {
    if (s>e) { return NULL;}
    int mid = s + (e-s)/2;
    root = buildTree(root,arr[mid]);
    root->left = balanceBTree(root->left,s,mid-1);
    root->right = balanceBTree(root->right,mid+1,e);
    return root;
}

int main() {
	int n;
	cin>>n;
	while(n>0) {
		int size;
		cin>>size;
		node *root = NULL;
		for(int i=0;i<size;i++) {
			cin>>arr[i];
		}
        root = balanceBTree(root,0,size-1);
		printInOrder(root);
        cout<<endl;
		delete root;
		n--;
	}

	return 0;
}
