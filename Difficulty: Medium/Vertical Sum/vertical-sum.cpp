/* Structure of binary tree node
class Node{
public:
    int data;
    Node *left, *right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
};
*/

#include <vector>
#include <map>

class Solution {
  private:
    // Helper function to traverse the tree and accumulate sums
    void calculateVerticalSum(Node* root, int hd, std::map<int, int>& mp) {
        if (root == nullptr) {
            return;
        }

        // Add current node's data to its corresponding vertical line sum
        mp[hd] += root->data;

        // Traverse left subtree with horizontal distance - 1
        calculateVerticalSum(root->left, hd - 1, mp);

        // Traverse right subtree with horizontal distance + 1
        calculateVerticalSum(root->right, hd + 1, mp);
    }

  public:
    std::vector<int> verticalSum(Node* root) {
        std::map<int, int> mp;
        std::vector<int> result;

        // Populate the map with vertical line sums
        calculateVerticalSum(root, 0, mp);

        // Extract sums from the map (automatically sorted from left-most to right-most)
        for (auto const& [hd, sum] : mp) {
            result.push_back(sum);
        }

        return result;
    }
};