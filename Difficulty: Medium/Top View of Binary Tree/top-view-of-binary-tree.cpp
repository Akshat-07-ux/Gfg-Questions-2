/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> result;
        if (root == nullptr) return result;

        // map: stores {horizontal_distance, node_data}
        // map is used because it keeps keys sorted (leftmost to rightmost)
        map<int, int> topNodes;
        
        // queue: stores {Node*, horizontal_distance}
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* curr = it.first;
            int hd = it.second;

            // If this horizontal distance is seen for the first time, 
            // it's the topmost node for that vertical line.
            if (topNodes.find(hd) == topNodes.end()) {
                topNodes[hd] = curr->data;
            }

            if (curr->left) {
                q.push({curr->left, hd - 1});
            }
            if (curr->right) {
                q.push({curr->right, hd + 1});
            }
        }

        // Extract values from the map (already sorted by HD)
        for (auto const& [hd, val] : topNodes) {
            result.push_back(val);
        }

        return result;
    }
};