#include <vector>
#include <unordered_map>

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
};*/

class Solution {
private:
    Node* buildTree(int preStart, int preEnd, int mirrorStart, int mirrorEnd, 
                   const std::vector<int>& pre, 
                   const std::unordered_map<int, int>& mirrorIndexMap) {
        if (preStart > preEnd) {
            return nullptr;
        }

        // The first element in pre[] is the root of the current subtree
        Node* root = new Node(pre[preStart]);

        // Base case: If the current subtree has only one node, return it
        if (preStart == preEnd) {
            return root;
        }

        // The second element in pre[] is the root of the left subtree
        int leftRootVal = pre[preStart + 1];

        // Find the index of the left root value in preMirror[]
        // In preMirror[], this node marks the start of the mirrored left subtree (original right subtree)
        int mirrorIndex = mirrorIndexMap.at(leftRootVal);

        // Calculate the number of elements in the left subtree
        int leftSubtreeSize = mirrorEnd - mirrorIndex + 1;

        // Recursively build the left subtree
        root->left = buildTree(preStart + 1, preStart + leftSubtreeSize, 
                               mirrorIndex, mirrorEnd, 
                               pre, mirrorIndexMap);

        // Recursively build the right subtree
        root->right = buildTree(preStart + leftSubtreeSize + 1, preEnd, 
                                mirrorStart + 1, mirrorIndex - 1, 
                                pre, mirrorIndexMap);

        return root;
    }

public:
    Node *constructBinaryTree(std::vector<int> &pre, std::vector<int> &preMirror) {
        int n = pre.size();
        if (n == 0) return nullptr;

        // Hash map to store the value -> index mapping for preMirror[]
        std::unordered_map<int, int> mirrorIndexMap;
        for (int i = 0; i < n; ++i) {
            mirrorIndexMap[preMirror[i]] = i;
        }

        return buildTree(0, n - 1, 0, n - 1, pre, mirrorIndexMap);
    }
};