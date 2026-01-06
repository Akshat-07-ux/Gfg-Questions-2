class Solution {
  public:
    Node *insertAtFront(Node *head, int x) {
        Node* newNode = new Node(x);  // create new node
        newNode->next = head;         // point to current head
        return newNode;               // new node becomes head
    }
};
