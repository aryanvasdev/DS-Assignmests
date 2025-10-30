void removeLoop(Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break; 
        }
    }

    if (slow != fast) {
        return;
    }

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    Node* tailFinder = slow;
    while (tailFinder->next != slow) {
        tailFinder = tailFinder->next;
    }

    tailFinder->next = NULL; 
}