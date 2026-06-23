/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

class Solution {
  public:
    Node* sortList(Node* head) {
        // Base case: if the list is empty or has only one element
        if (!head || !head->next) {
            return head;
        }
        
        Node* prev = head;
        Node* curr = head->next;
        
        while (curr != nullptr) {
            // If the current node is negative, shift it to the front
            if (curr->data < 0) {
                // Detach curr from its current position
                prev->next = curr->next;
                
                // Move curr to the front of the list
                curr->next = head;
                head = curr;
                
                // Update curr to point to the next node to process
                curr = prev->next;
            } else {
                // If it's positive, it's already in the correct relative order
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};