/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node* insertAtBeginning(Node* tail, int key) {
        // Step 1: Create the new node
        Node* newNode = new Node(key);
        
        // Step 2: Handle empty list scenario
        if (tail == nullptr) {
            newNode->next = newNode; // Points to itself
            return newNode;          // It is the head of the list
        }
        
        // Step 3: Handle non-empty list scenario
        newNode->next = tail->next;  // New node points to the current head
        tail->next = newNode;        // Tail points to the new node (making it the new head)
        
        return newNode;              // Return the new head
    }
};