/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        if (!head || !head->next) return 0;
        
        Node *slow = head, *fast = head;
        
        // Step 1: Detect loop using Floyd’s cycle-finding algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) { // loop detected
                return countLoopLength(slow);
            }
        }
        return 0; // no loop
    }
    
  private:
    int countLoopLength(Node* nodeInLoop) {
        int count = 1;
        Node* temp = nodeInLoop->next;
        
        while (temp != nodeInLoop) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};
