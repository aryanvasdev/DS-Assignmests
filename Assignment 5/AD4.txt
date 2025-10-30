Node* rotateLeft(Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    Node* last = head;
    int n = 1;
    while (last->next != NULL) {
        last = last->next;
        n++;
    }

    k = k % n;
    if (k == 0) {
        return head;
    }

    Node* newTail = head;
    for (int i = 0; i < k - 1; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;

    last->next = head;
    newTail->next = NULL;

    return newHead;
}