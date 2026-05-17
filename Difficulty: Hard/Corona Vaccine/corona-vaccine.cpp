/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    int vaccineCount = 0;

    // Helper function that returns the state of the node
    // 0: Node has a vaccine
    // 1: Node is covered (but doesn't have a vaccine)
    // 2: Node is uncovered
    int dfs(Node* root) {
        if (root == NULL) {
            return 1; // Null nodes are considered covered
        }

        int leftState = dfs(root->left);
        int rightState = dfs(root->right);

        // Case 1: If any child is UNCOVERED, this current node MUST install a vaccine.
        if (leftState == 2 || rightState == 2) {
            vaccineCount++;
            return 0; // Current node now HAS a vaccine
        }

        // Case 2: If any child HAS a vaccine, the current node becomes COVERED automatically.
        if (leftState == 0 || rightState == 0) {
            return 1; // Current node is COVERED
        }

        // Case 3: If both children are COVERED (but don't have vaccine themselves),
        // the current node is UNCOVERED and depends on its parent to save it.
        return 2;
    }

  public:
    int supplyVaccine(Node* root) {
        vaccineCount = 0;
        
        // If the root itself is left UNCOVERED by its children, 
        // it doesn't have a parent to save it, so we must install a vaccine at the root.
        if (dfs(root) == 2) {
            vaccineCount++;
        }
        
        return vaccineCount;
    }
};