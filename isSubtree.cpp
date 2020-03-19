bool isSubTree(Node *T, Node *S) {
    if(S == nullptr && T == nullptr)
        return true;
    if(T == nullptr || S == nullptr)
        return false;
    else{
        bool temp = false;
        if(T->data == S->data)
            temp = isSubTree(T->left, S->left) && isSubTree(T->right, S->right);
        return temp || isSubTree(T->left, S) || isSubTree(T->right, S);
    }
}
