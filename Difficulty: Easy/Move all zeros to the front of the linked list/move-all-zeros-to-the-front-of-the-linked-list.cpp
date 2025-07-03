class Solution {
  public:
    void moveZeroes(struct Node*& head) {
        if (!head || !head->next) return;  // Empty or single-node list

        Node* curr = head;
        Node* prev = nullptr;

        while (curr) {
            if (curr->data == 0) {
                if (prev) {
                    // Remove curr from current position
                    prev->next = curr->next;
                    // Insert at head
                    curr->next = head;
                    head = curr;
                    // Move curr to next node after prev
                    curr = prev->next;
                } else {
                    // curr is already at head, move forward
                    prev = curr;
                    curr = curr->next;
                }
            } else {
                // Move forward
                prev = curr;
                curr = curr->next;
            }
        }
    }
};
