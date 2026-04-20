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
    Node* removeLastNode(Node* head) {
        // Edge Case: If the list is empty, return NULL
        if (head == NULL) {
            return NULL;
        }

        // Edge Case: If there is only one node, delete it and return NULL
        if (head->next == NULL) {
            delete head;
            return NULL;
        }

        // Traverse to find the second-to-last node
        Node* curr = head;
        while (curr->next->next != NULL) {
            curr = curr->next;
        }

        // 'curr' is now the second-to-last node
        // Delete the last node to prevent memory leaks
        delete (curr->next);
        
        // Set the second-to-last node's next to NULL
        curr->next = NULL;

        return head;
    }
};