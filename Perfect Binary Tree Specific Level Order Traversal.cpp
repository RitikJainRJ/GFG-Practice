#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data) {
    Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

void printSpecificLevelOrder(Node *root) {
    deque<Node*> q;

    q.push_back(root);
    while(!q.empty()){
        int size = q.size();
        int l = 0, r = size - 1;
        bool flag = false;

        while(l <= r){
            if(!flag){
                cout << q[l]->data << " ";
                flag = true;
                l++;
            }
            else{
                cout << q[r]->data << " ";
                flag = false;
                r--;
            }
        }
        while(size--){
            Node *temp = q.front();
            q.pop_front();

            if(temp->left)
                q.push_back(temp->left);
            if(temp->right)
                q.push_back(temp->right);
        }
    }
}


int main() {
    Node *root = newNode(1);

    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
    root->right->right->right  = newNode(15);
    root->left->left->left->left  = newNode(16);
    root->left->left->left->right  = newNode(17);
    root->left->left->right->left  = newNode(18);
    root->left->left->right->right  = newNode(19);
    root->left->right->left->left  = newNode(20);
    root->left->right->left->right  = newNode(21);
    root->left->right->right->left  = newNode(22);
    root->left->right->right->right  = newNode(23);
    root->right->left->left->left  = newNode(24);
    root->right->left->left->right  = newNode(25);
    root->right->left->right->left  = newNode(26);
    root->right->left->right->right  = newNode(27);
    root->right->right->left->left  = newNode(28);
    root->right->right->left->right  = newNode(29);
    root->right->right->right->left  = newNode(30);
    root->right->right->right->right  = newNode(31);
    printSpecificLevelOrder(root);
    return 0;
}
