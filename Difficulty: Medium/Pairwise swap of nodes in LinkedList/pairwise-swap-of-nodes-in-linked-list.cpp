/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to swap elements pairwise.
struct Node* pairwise_swap(struct Node* head) {
    // Base case: empty list or only one node
    if (head == NULL || head->next == NULL)
        return head;

    Node* prev = NULL;
    Node* curr = head;
    head = head->next; // After swap, the second node becomes the new head

    while (curr != NULL && curr->next != NULL) {
        Node* next = curr->next;
        Node* nextPair = next->next;

        // Swap
        next->next = curr;
        curr->next = nextPair;

        // Connect the previous pair to the current swapped pair
        if (prev != NULL)
            prev->next = next;

        // Move to the next pair
        prev = curr;
        curr = nextPair;
    }

    return head;
}
