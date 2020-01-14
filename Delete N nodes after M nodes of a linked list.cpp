/*
Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.
*/
void linkdelete(Node  *head, int m, int n){
    Node *temp1 = nullptr, *temp2 = nullptr;
    int k = m, l = n;

    temp1 = head;
    while(k > 1){
        if(temp1 == nullptr)
            return;
        k--;
        temp1 = temp1->next;
    }
    while(temp1 != nullptr || temp1->next != nullptr){
        l = n;
        temp2 = temp1;
        while(l--){
            temp2 = temp2->next;
            if(temp2 == nullptr){
                temp1->next = nullptr;
                return;
            }
        }
        temp1->next = temp2->next;
        k = m;
        while(k--){
            temp1 = temp1->next;
            if(temp1 == nullptr)
                return;
        }
    }
}

