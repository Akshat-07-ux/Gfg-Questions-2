/*
structure of the node of the linked list is
struct Node
{
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node *> mergeList(struct Node **head1, struct Node **head2) {
        // If either list is empty, there's nothing to merge
        if (*head1 == NULL || *head2 == NULL) {
            return {*head1, *head2};
        }

        Node *curr1 = *head1;
        Node *curr2 = *head2;

        // We iterate as long as there is a current node in list 1 
        // AND a node in list 2 to insert.
        while (curr1 != NULL && curr2 != NULL) {
            Node *next1 = curr1->next;
            Node *next2 = curr2->next;

            // Link the node from list 2 into list 1
            curr1->next = curr2;
            curr2->next = next1;

            // Move the head of list 2 to the next available node
            *head2 = next2;

            // Move curr1 forward. 
            // We move to next1 (the original next) to maintain alternate insertion.
            curr1 = next1;
            
            // Move curr2 forward to the next node to be inserted
            curr2 = next2;
        }

        return {*head1, *head2};
    }
};