#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

void sortedBST(int);
Node* _sortedBST(int[], int, int);
void preOrder(Node*);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    sortedBST(n);
	    cout << endl;
	}
	return 0;
}

void sortedBST(int n){
    int arr[n];
    Node *root = nullptr;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    root = _sortedBST(arr, 0, n - 1);
    preOrder(root);
}

void preOrder(Node *root){
    if(root){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

Node* _sortedBST(int arr[], int l, int r){
    if(l > r)
        return nullptr;
    else{
        int m = (l + r) / 2;
        Node *root = new Node(arr[m]);
        root->left = _sortedBST(arr, l , m - 1);
        root->right = _sortedBST(arr, m + 1, r);
        return root;
    }
}
