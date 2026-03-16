/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

#include <unordered_map>

class Solution {
  public:
    int countAllPaths(Node *root, int k) {
        // Map to store (prefix_sum, count)
        std::unordered_map<long long, int> prefixSums;
        
        // Base case: a prefix sum of 0 is always seen once (for paths starting from root)
        prefixSums[0] = 1;
        
        return solve(root, 0, k, prefixSums);
    }

  private:
    int solve(Node* node, long long currentSum, int k, std::unordered_map<long long, int>& prefixSums) {
        if (!node) return 0;

        int count = 0;
        currentSum += node->data;

        // If (currentSum - k) exists in the map, it means there's a 
        // downward path ending here that sums to k.
        if (prefixSums.find(currentSum - k) != prefixSums.end()) {
            count += prefixSums[currentSum - k];
        }

        // Add currentSum to map for children to use
        prefixSums[currentSum]++;

        // Recurse to left and right
        count += solve(node->left, currentSum, k, prefixSums);
        count += solve(node->right, currentSum, k, prefixSums);

        // Backtrack: Remove currentSum from map so it doesn't affect 
        // nodes in other branches (not downward from here)
        prefixSums[currentSum]--;
        
        return count;
    }
};