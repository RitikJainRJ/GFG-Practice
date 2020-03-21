node *reverse(node *head, int k){
    node *p = nullptr, *q = nullptr, *c = nullptr;
    node *tail = nullptr, *temp = nullptr;
    int m;

    m = k;
    tail = head;
    c = head;
    while(m--){
        q = c->next;
        c->next = p;
        p = c;
        c = q;
    }
    head = p;
    while(c){
        p = nullptr;
        m = k;
        temp = c;
        while(m--){
            q = c->next;
            c->next = p;
            p = c;
            c = q;
            if(c == nullptr)
                break;
        }
        tail->next = p;
        tail = temp;
    }
    return head;
}
