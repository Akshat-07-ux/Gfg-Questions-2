class Solution {
public:
    bool checkUtil(int pre[], int in[], int post[], int n) {
        // If all arrays are empty, it's valid
        if (n == 0) return true;
        
        // If arrays have one element, they must be equal
        if (n == 1) 
            return (pre[0] == in[0] && in[0] == post[0]);
        
        // Root must be same in preorder and postorder
        if (pre[0] != post[n-1]) return false;
        
        // Find root in inorder
        int root = pre[0];
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (in[i] == root) {
                idx = i;
                break;
            }
        }
        if (idx == -1) return false; // root not found in inorder
        
        // Left subtree size = idx, right subtree size = n-idx-1
        int leftSize = idx;
        int rightSize = n - idx - 1;
        
        // Recursively check left and right subtrees
        bool leftValid = checkUtil(pre+1, in, post, leftSize);
        bool rightValid = checkUtil(pre+1+leftSize, in+idx+1, post+leftSize, rightSize);
        
        return leftValid && rightValid;
    }

    bool checktree(int preorder[], int inorder[], int postorder[], int N) {
        return checkUtil(preorder, inorder, postorder, N);
    }
};
