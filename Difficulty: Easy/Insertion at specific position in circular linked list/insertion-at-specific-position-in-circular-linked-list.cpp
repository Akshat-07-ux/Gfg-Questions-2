class Solution {
  public:
    Node* insertNodeAtPos(Node* head, int pos, int x) {
        Node* newNode = new Node(x);
        
        // Scenario 1: Insertion at the very beginning (Position 0)
        if (pos == 0) {
            if (head == NULL) {
                newNode->next = newNode; // Points to itself
                return newNode;
            }
            
            // Find the last node (tail) to maintain the circular nature
            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            
            newNode->next = head;
            tail->next = newNode; // Tail now points to the new head
            return newNode;       // Return newNode as the updated head
        }
        
        // Scenario 2: Insertion at any other position (pos > 0)
        Node* curr = head;
        // Traverse to the node just before the insertion position
        for (int i = 0; i < pos - 1; i++) {
            curr = curr->next;
        }
        
        // Insert the new node into the sequence
        newNode->next = curr->next;
        curr->next = newNode;
        
        return head; // The head remains unchanged
    }
};