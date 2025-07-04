class Solution {
  public:
    Node* zigZag(Node* head) {
        if (!head || !head->next) return head;

        Node* curr = head;
        bool less = true; // We want curr <= curr->next

        while (curr && curr->next) {
            if (less) {
                if (curr->data > curr->next->data) {
                    swap(curr->data, curr->next->data);
                }
            } else {
                if (curr->data < curr->next->data) {
                    swap(curr->data, curr->next->data);
                }
            }
            curr = curr->next;
            less = !less; // toggle the condition
        }

        return head;
    }
};
