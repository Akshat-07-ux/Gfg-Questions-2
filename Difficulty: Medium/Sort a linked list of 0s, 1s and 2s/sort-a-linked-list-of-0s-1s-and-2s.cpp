/* Node is defined as
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
  public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head; // empty or single node
        
        // Create dummy heads and tails for 0, 1, 2 lists
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        
        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;
        
        // Traverse original list
        Node* curr = head;
        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }
        
        // Connect the three lists: 0 → 1 → 2
        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = nullptr;
        
        // Head of new list
        Node* newHead = zeroHead->next;
        
        // Free dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return newHead;
    }
};
