ListNode* swapPairs(ListNode* head) {
    ListNode *t1 = nullptr, *t2 = nullptr, *p = nullptr;
    bool flag = false;

    t1 = head;
    while(t1 && t1->next){
        t2 = t1->next;
        if(flag == false){
            head = t2;
            flag = true;
        }
        t1->next = t2->next;
        t2->next = t1;
        if(p)
            p->next = t2;
        p = t1;
        t1 = t1->next;
    }
    return head;
}
