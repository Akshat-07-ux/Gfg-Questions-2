/*
struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
};
*/

class Solution {
  public:
    int getLength(Node *head) {
        // Base case: If the list is empty, the length is 0
        if (head == NULL) {
            return 0;
        }
        
        int count = 1;
        Node *current = head;
        
        // Traverse until the next node points back to the head
        while (current->next != head) {
            count++;
            current = current->next;
        }
        
        return count;
    }
};