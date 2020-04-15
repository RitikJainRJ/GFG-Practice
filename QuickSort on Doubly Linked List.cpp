void partition(Node *left, Node *right){
    Node *p = nullptr, *i = nullptr, *j = nullptr;

    p = right;
    i = left->prev;
    j = left;
    while(j != right->next){
        if(j->data <= p->data){
            if(i == nullptr)
                i = left;
            else
                i = i->next;
            swap(i->data, j->data);
        }
        j = j->next;
    }
    return i;
}

void quickSort(Node *left, Node *right){
    if(right != nullptr && left != right && right->next != left){
        Node *p = partition(left, right);
        quickSort(left, p->prev);
        quickSort(p->next, right);
    }
}
