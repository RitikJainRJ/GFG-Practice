node* getTail(node*);
node* _quickSort(node*, node*);
node* partition(node*, node*, node**, node**);

void quickSort(node **headRef){
    *headRef = _quickSort(*headRef, getTail(*headRef));
}

node* getTail(node *head){
    while(head->next)
        head = head->next;
    return head;
}

node* _quickSort(node *left, node *right){
    if(left == nullptr || left == right){
        return left;
    }
    node *newHead = nullptr, *newTail = nullptr, *pivot = nullptr;

    pivot = partition(left, right, &newHead, &newTail);

    if(pivot != newHead){
        node *temp = nullptr;
        temp = newHead;
        while(temp->next != pivot)
            temp = temp->next;
        temp->next = nullptr;
        newHead = _quickSort(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }
    pivot->next = _quickSort(pivot->next, newTail);
    return newHead;
}

node* partition(node *left, node *right, node **newHead, node **newTail){
    node *pivot = nullptr, *prev = nullptr;

    pivot = right;
    while(left != pivot){
        if(pivot->data < left->data){
            node *temp = nullptr;

            if(prev)
                prev->next = left->next;
            temp = left->next;
            left->next = nullptr;
            right->next = left;
            right = left;
            left = temp;
        }
        else{
            if((*newHead) == nullptr)
                *newHead = left;
            prev = left;
            left = left->next;
        }
    }
    if(*newHead == nullptr)
        *newHead = pivot;
    *newTail = right;
    return pivot;
}
