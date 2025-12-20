class Solution {
  public:
    bool searchLinkedList(Node *head, int x) {
        Node* curr = head;
        
        while (curr != NULL) {
            if (curr->data == x)
                return true;
            curr = curr->next;
        }
        
        return false;
    }
};
