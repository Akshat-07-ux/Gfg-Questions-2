#include <bits/stdc++.h>
using namespace std;

/*
// A Binary Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

class Solution {
  public:
    vector<int> printCousins(Node* root, Node* node_to_find) {
        if (!root || root == node_to_find) return {-1};

        queue<Node*> q;
        q.push(root);
        bool foundParent = false;

        while (!q.empty()) {
            int size = q.size();
            vector<int> levelNodes;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                // Check if current node is parent of the target node
                if ((curr->left == node_to_find) || (curr->right == node_to_find)) {
                    foundParent = true; // siblings found, don’t push them
                } else {
                    if (curr->left) q.push(curr->left);
                    if (curr->right) q.push(curr->right);
                }
            }

            // If we found the parent at this level, the current queue holds cousins
            if (foundParent) {
                vector<int> cousins;
                while (!q.empty()) {
                    cousins.push_back(q.front()->data);
                    q.pop();
                }
                if (cousins.empty()) return {-1};
                return cousins;
            }
        }
        return {-1}; // no cousins found
    }
};
