void swapNodes(Node **head, int x, int y){
    if(x == y)
        return;
    Node *currX = nullptr, *currY = nullptr;
    Node *prevX = nullptr, *prevY = nullptr;

    currX = *head;
    while(currX && currX->data != x){
        prevX = currX;
        currX = currX->next;
    }
    currY = *head;
    while(currY && currY->data != y){
        prevY = currY;
        currY = currY->next;
    }

    if(!currX || !currY)
        return;

    if(prevX)
        prevX->next = currY;
    else
        *head = currY;
    if(prevY)
        prevY->next = currX;
    else
        *head = currX;
    Node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}
