/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    // Function to count nodes using Morris Traversal
    int countNodes(Node* root) {
        int count = 0;
        Node* curr = root;
        while (curr) {
            if (!curr->left) {
                count++;
                curr = curr->right;
            } else {
                Node* pre = curr->left;
                while (pre->right && pre->right != curr)
                    pre = pre->right;
                if (!pre->right) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = nullptr;
                    count++;
                    curr = curr->right;
                }
            }
        }
        return count;
    }

    // Function to find median using Morris Traversal
    int findMedian(Node* root) {
        if (!root) return 0;

        int n = countNodes(root);
        int currCount = 0;
        Node* curr = root;
        int prevVal = 0, currVal = 0;

        while (curr) {
            if (!curr->left) {
                currCount++;
                // check if current node is the median
                if (n % 2 != 0 && currCount == (n + 1) / 2)
                    return curr->data;
                else if (n % 2 == 0 && currCount == (n / 2))
                    prevVal = curr->data;
                else if (n % 2 == 0 && currCount == (n / 2) + 1)
                    return prevVal; // median as per problem definition (Vn/2)
                curr = curr->right;
            } else {
                Node* pre = curr->left;
                while (pre->right && pre->right != curr)
                    pre = pre->right;
                if (!pre->right) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = nullptr;
                    currCount++;
                    if (n % 2 != 0 && currCount == (n + 1) / 2)
                        return curr->data;
                    else if (n % 2 == 0 && currCount == (n / 2))
                        prevVal = curr->data;
                    else if (n % 2 == 0 && currCount == (n / 2) + 1)
                        return prevVal;
                    curr = curr->right;
                }
            }
        }
        return -1; // shouldn't reach here
    }
};
