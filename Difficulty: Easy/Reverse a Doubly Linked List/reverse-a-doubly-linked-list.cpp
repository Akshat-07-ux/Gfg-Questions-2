/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
*/

class Solution {
  public:
    Node *reverse(Node *head) {
        if (!head) return head; // empty list
        
        Node* curr = head;
        Node* temp = nullptr;
        
        // Traverse the list and swap next and prev for each node
        while (curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev; // move to next node (was prev before swap)
        }
        
        // After the loop, temp will point to the node before NULL (old head's prev)
        if (temp != nullptr) {
            head = temp->prev; // new head
        }
        
        return head;
    }
};
