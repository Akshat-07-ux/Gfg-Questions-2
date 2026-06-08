/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  private:
    // Helper function to reverse a singly linked list
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* nextNode = nullptr;
        
        while (curr != nullptr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

  public:
    Node *compute(Node *head) {
        if (!head || !head->next) {
            return head;
        }

        // Step 1: Reverse the linked list
        head = reverseList(head);

        // Step 2: Traverse and remove nodes smaller than the max seen so far
        Node* curr = head;
        Node* maxNode = head; // The first node in reversed list is always kept
        
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->data < maxNode->data) {
                // Skip the next node because it's smaller than the max to its right
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp; // Free memory
            } else {
                // Next node is valid, move forward and update the maxNode
                curr = curr->next;
                maxNode = curr;
            }
        }

        // Step 3: Reverse the list again to restore the original relative order
        return reverseList(head);
    }
};