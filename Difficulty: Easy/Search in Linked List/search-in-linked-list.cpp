class Solution {
  public:
    bool searchKey(Node* head, int key) {
        Node* curr = head;

        while (curr != NULL) {
            if (curr->data == key)
                return true;

            curr = curr->next;
        }

        return false;
    }
};