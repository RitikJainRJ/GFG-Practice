int _findDist(Node*, int, int, Node*&);
int getElement(Node*, int);

int findDist(Node* root, int a, int b) {
    Node *lca = nullptr;
    int h1, h2;

    _findDist(root, a, b, lca);
    h1 = getElement(lca, a);
    h2 = getElement(lca, b);
    return h1 + h2;
}

int _findDist(Node *root, int a, int b, Node *&lca){
    if(root == nullptr){
        return 0;
    }
    else{
        int left = _findDist(root->left, a, b, lca);
        int right = _findDist(root->right, a, b, lca);
        int temp = 0;
        if(root->data == a || root->data == b)
            temp = 1;
        if(left == 1 && right == 1)
            lca = root;
        else if(left == 1 && temp == 1)
            lca = root;
        else if(right == 1 && temp == 1)
            lca = root;

        return left + right + temp;
    }
}

int getElement(Node *root, int data){
    queue<Node*> q;
    q.push(root);
    int level = 0;

    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node *temp = q.front();
            q.pop();
            if(temp->data == data)
                return level;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        level++;
    }
    return level;
}
