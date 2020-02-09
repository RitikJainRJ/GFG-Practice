void postOrder(Node* root){
    stack<Node*> s;
    Node *t = root;

    do{
        while(t){
            if(t->right)
                s.push(t->right);
            s.push(t);
            t = t->left;
        }
        t = s.top();
        s.pop();
        if(t->right && !s.empty() && t->right == s.top()){
            Node *temp = s.top();
            s.pop();
            s.push(t);
            t = temp;
        }
        else{
            cout << t->data << " ";
            t = nullptr;
        }
    }while(!s.empty());
}

