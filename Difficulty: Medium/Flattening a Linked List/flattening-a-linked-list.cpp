class Solution {
  public:
    Node *flatten(Node *root) {
        // Base case: empty list or single head node
        if (!root || !root->next)
            return root;

        // Recursively flatten the rest of the list
        root->next = flatten(root->next);

        // Merge current list with flattened next list
        root = merge(root, root->next);

        return root;
    }

  private:
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result;

        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        result->next = NULL;
        return result;
    }
};
