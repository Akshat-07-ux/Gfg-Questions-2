class Solution {
  public:
    struct Node* partition(struct Node* head, int x) {
        if (!head) return head;
        
        // Dummy heads and tails
        Node* lessHead = new Node(0);
        Node* equalHead = new Node(0);
        Node* greaterHead = new Node(0);
        
        Node* lessTail = lessHead;
        Node* equalTail = equalHead;
        Node* greaterTail = greaterHead;
        
        // Traverse and distribute nodes
        Node* curr = head;
        while (curr) {
            if (curr->data < x) {
                lessTail->next = curr;
                lessTail = curr;
            } else if (curr->data == x) {
                equalTail->next = curr;
                equalTail = curr;
            } else {
                greaterTail->next = curr;
                greaterTail = curr;
            }
            curr = curr->next;
        }
        
        // Combine the three lists
        greaterTail->next = NULL;
        
        // connect equal after less
        if (equalHead->next) {
            lessTail->next = equalHead->next;
            equalTail->next = greaterHead->next;
        } else {
            lessTail->next = greaterHead->next;
        }
        
        Node* newHead = lessHead->next ? lessHead->next : 
                        (equalHead->next ? equalHead->next : greaterHead->next);
        
        // Free dummy nodes
        delete lessHead;
        delete equalHead;
        delete greaterHead;
        
        return newHead;
    }
};
