class Solution {
  public:
    // Helper function to reverse a linked list and return new head
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    Node *reverse(Node *head, int k) {
        if (!head || !head->next || k <= 0) return head;

        // Step 1: Find the kth node
        Node* curr = head;
        Node* prevK = NULL;
        int count = 0;

        while (curr && count < k) {
            prevK = curr;
            curr = curr->next;
            count++;
        }

        // Now head to prevK is first part (k nodes), curr is start of second part
        prevK->next = NULL; // disconnect first and second part

        // Step 2: Reverse both parts
        Node* firstReversed = reverseList(head);
        Node* secondReversed = reverseList(curr);

        // Step 3: Attach the reversed second part to the end of reversed first part
        Node* temp = firstReversed;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = secondReversed;

        return firstReversed;
    }
};
