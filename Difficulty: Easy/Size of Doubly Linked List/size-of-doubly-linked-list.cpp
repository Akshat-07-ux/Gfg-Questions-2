/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
*/

class Solution {
  public:
    int findSize(Node *head) {
        // Initialize count to 0
        int count = 0;
        
        // Pointer to traverse the list starting from head
        Node* current = head;
        
        // Traverse the list until the end (nullptr) is reached
        while (current != nullptr) {
            count++;
            current = current->next; // Move to the next node
        }
        
        return count;
    }
};