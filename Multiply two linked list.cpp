int reverse(Node*&);

long long  multiplyTwoLists(Node* l1, Node* l2){
    Node *first = nullptr, *second = nullptr;
    Node *res = nullptr, *res1 = nullptr, *res2 = nullptr;
    int len1, len2, c;

    len1 = reverse(l1);
    len2 = reverse(l2);
    for(int i = 0; i < len1 + len2 + 1; i++){
        if(res == nullptr){
            res = new Node(0);
            res1 = res;
        }
        else{
            res1->next = new Node(0);
            res1 = res1->next;
        }
    }
    second = l2;
    res1 = res;
    while(second){
        c = 0;
        first = l1;
        res2 = res1;
        while(first){
            int mul = first->data * second->data + c;

            res2->data += mul % 10;
            c = mul / 10 + res2->data / 10;
            res2->data = res2->data % 10;
            res2 = res2->next;
            first = first->next;
        }
        if(c > 0){
            res2->data += c;
        }
        second = second->next;
        res1 = res1->next;
    }
    reverse(res);
    reverse(l1);
    reverse(l2);
    while(res->data == 0)
        res = res->next;
    res1 = res;
    long long ans = 0;
    while(res1){
        ans = ans * 10 + res1->data;
        res1 = res1->next;
    }
    return ans;
}

int reverse(Node *&head){
    int len = 0;
    Node *p = nullptr, *c = nullptr, *q = nullptr;

    c = head;
    while(c){
        len++;
        q = c->next;
        c->next = p;
        p = c;
        c = q;
    }
    head = p;
    return len;
}
