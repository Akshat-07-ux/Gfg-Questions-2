/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  private:
    // Function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        Node* result = nullptr;

        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    // Function to find the middle node (for splitting)
    Node* getMiddle(Node* head) {
        if (!head) return head;

        Node* slow = head;
        Node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

  public:
    Node* mergeSort(Node* head) {
        // Base case: 0 or 1 node
        if (!head || !head->next) return head;

        // Find middle
        Node* middle = getMiddle(head);
        Node* nextOfMiddle = middle->next;

        // Split the list
        middle->next = nullptr;

        // Recursively sort both halves
        Node* left = mergeSort(head);
        Node* right = mergeSort(nextOfMiddle);

        // Merge sorted halves
        return merge(left, right);
    }
};
