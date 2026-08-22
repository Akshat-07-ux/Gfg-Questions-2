/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  private:
    // Helper function to find Lowest Common Ancestor (LCA)
    Node* findLCA(Node* root, int p, int q) {
        if (!root || root->data == p || root->data == q) {
            return root;
        }

        Node* leftLCA = findLCA(root->left, p, q);
        Node* rightLCA = findLCA(root->right, p, q);

        if (leftLCA && rightLCA) return root;
        return leftLCA ? leftLCA : rightLCA;
    }

    // Helper function to count turns from a start node down to a target value
    // turnCount: current turns, turnRight: true if moving right, false if moving left
    bool countTurns(Node* root, int target, bool turnRight, int &turns) {
        if (!root) return false;

        if (root->data == target) return true;

        // Try going left (turnRight = false)
        if (countTurns(root->left, target, false, turns)) {
            if (turnRight) turns++; // Turn occurred
            return true;
        }

        // Try going right (turnRight = true)
        if (countTurns(root->right, target, true, turns)) {
            if (!turnRight) turns++; // Turn occurred
            return true;
        }

        return false;
    }

  public:
    int numberOfTurns(Node* root, int p, int q) {
        Node* lca = findLCA(root, p, q);
        if (!lca) return -1;

        int count = 0;

        // Case 1: LCA is node p
        if (lca->data == p) {
            int turns = 0;
            countTurns(lca->left, q, false, turns);
            countTurns(lca->right, q, true, turns);
            return (turns == 0) ? -1 : turns;
        }

        // Case 2: LCA is node q
        if (lca->data == q) {
            int turns = 0;
            countTurns(lca->left, p, false, turns);
            countTurns(lca->right, p, true, turns);
            return (turns == 0) ? -1 : turns;
        }

        // Case 3: LCA is an ancestor of both p and q
        int turnsP = 0, turnsQ = 0;
        countTurns(lca->left, p, false, turnsP);
        countTurns(lca->right, p, true, turnsP);

        countTurns(lca->left, q, false, turnsQ);
        countTurns(lca->right, q, true, turnsQ);

        // Junction at LCA adds 1 turn between p and q path
        count = turnsP + turnsQ + 1;

        return (count == 0) ? -1 : count;
    }
};