#include <bits/stdc++.h>
using namespace std;

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        if (!root) return {};
        
        // Map to store horizontal distance → last node's value at that distance
        map<int, int> hdNodeMap;
        
        // Queue for level order traversal; stores pair<Node*, horizontal_distance>
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            
            Node* curr = front.first;
            int hd = front.second;
            
            // For bottom view, we update every time (the last seen at hd)
            hdNodeMap[hd] = curr->data;
            
            // Move left → hd - 1
            if (curr->left)
                q.push({curr->left, hd - 1});
            
            // Move right → hd + 1
            if (curr->right)
                q.push({curr->right, hd + 1});
        }
        
        // Extract result from map (sorted by hd)
        vector<int> bottomView;
        for (auto &entry : hdNodeMap) {
            bottomView.push_back(entry.second);
        }
        
        return bottomView;
    }
};
