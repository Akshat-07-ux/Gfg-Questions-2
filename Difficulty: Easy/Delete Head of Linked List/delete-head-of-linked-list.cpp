/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node *deleteHead(Node *head) {
        // Edge Case: If the linked list is empty
        if (head == NULL) {
            return NULL;
        }
        
        // Store the current head in a temporary pointer
        Node* temp = head;
        
        // Move the head pointer to the next node
        head = head->next;
        
        // Set the original head's next pointer to NULL as per instructions
        temp->next = NULL;
        
        // Delete the old head node from memory to prevent memory leaks
        delete temp;
        
        // Return the new head of the modified linked list
        return head;
    }
};