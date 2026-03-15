/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>> result;
        if (!root) return result;

        // map to store nodes at each horizontal distance
        // map<hd, vector of nodes at that hd>
        map<int, vector<int>> nodes;

        // queue for BFS: pair<Node*, horizontal_distance>
        queue<pair<Node*, int>> q;

        // Starting with root at distance 0
        q.push({root, 0});

        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();

            Node* curr = temp.first;
            int hd = temp.second;

            // Add current node's data to its vertical line
            nodes[hd].push_back(curr->data);

            // Left child has horizontal distance hd - 1
            if (curr->left) {
                q.push({curr->left, hd - 1});
            }

            // Right child has horizontal distance hd + 1
            if (curr->right) {
                q.push({curr->right, hd + 1});
            }
        }

        // Extracting from map (map is sorted by key/hd)
        for (auto const& [hd, values] : nodes) {
            result.push_back(values);
        }

        return result;
    }
};