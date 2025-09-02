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
    Node* swapKth(Node* head, int k) {
        if (!head) return head;

        // Count total nodes
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // If k is more than number of nodes
        if (k > n) return head;

        // If kth node from start and end are same
        if (2 * k - 1 == n) return head;

        // Find kth node from start
        Node* prevX = NULL;
        Node* currX = head;
        for (int i = 1; i < k; i++) {
            prevX = currX;
            currX = currX->next;
        }

        // Find kth node from end (which is (n-k+1)-th from start)
        Node* prevY = NULL;
        Node* currY = head;
        for (int i = 1; i < n - k + 1; i++) {
            prevY = currY;
            currY = currY->next;
        }

        // If previous nodes exist, update their next
        if (prevX) prevX->next = currY;
        if (prevY) prevY->next = currX;

        // Swap next pointers
        Node* tempNext = currX->next;
        currX->next = currY->next;
        currY->next = tempNext;

        // Change head if needed
        if (k == 1) head = currY;
        if (k == n) head = currX;

        return head;
    }
};
