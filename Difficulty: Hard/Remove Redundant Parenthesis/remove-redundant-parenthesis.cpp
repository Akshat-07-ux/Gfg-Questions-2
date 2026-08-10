#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    char val;
    Node* left;
    Node* right;
    Node(char c) : val(c), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    int getPrecedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0; // for non-operators or parentheses
    }

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    // Constructs Expression Tree from infix string
    Node* buildTree(const string& s) {
        stack<Node*> nodes;
        stack<char> ops;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (isalpha(c)) {
                nodes.push(new Node(c));
            } else if (c == '(') {
                ops.push(c);
            } else if (c == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    char op = ops.top();
                    ops.pop();

                    Node* right = nodes.top(); nodes.pop();
                    Node* left = nodes.top(); nodes.pop();

                    Node* parent = new Node(op);
                    parent->left = left;
                    parent->right = right;

                    nodes.push(parent);
                }
                if (!ops.empty()) ops.pop(); // Pop '('
            } else if (isOperator(c)) {
                while (!ops.empty() && getPrecedence(ops.top()) >= getPrecedence(c)) {
                    char op = ops.top();
                    ops.pop();

                    Node* right = nodes.top(); nodes.pop();
                    Node* left = nodes.top(); nodes.pop();

                    Node* parent = new Node(op);
                    parent->left = left;
                    parent->right = right;

                    nodes.push(parent);
                }
                ops.push(c);
            }
        }

        while (!ops.empty()) {
            char op = ops.top();
            ops.pop();

            Node* right = nodes.top(); nodes.pop();
            Node* left = nodes.top(); nodes.pop();

            Node* parent = new Node(op);
            parent->left = left;
            parent->right = right;

            nodes.push(parent);
        }

        return nodes.top();
    }

    // Recursively converts tree back to string with minimal parentheses
    string stringify(Node* root) {
        if (!root) return "";
        if (!root->left && !root->right) return string(1, root->val);

        int parentPrec = getPrecedence(root->val);

        // Process Left Subtree
        string leftStr = stringify(root->left);
        if (root->left && isOperator(root->left->val)) {
            int leftPrec = getPrecedence(root->left->val);
            if (leftPrec < parentPrec) {
                leftStr = "(" + leftStr + ")";
            }
        }

        // Process Right Subtree
        string rightStr = stringify(root->right);
        if (root->right && isOperator(root->right->val)) {
            int rightPrec = getPrecedence(root->right->val);
            
            // Needs parentheses if right child has lower precedence,
            // or equal precedence when parent is '-' or '/'
            if (rightPrec < parentPrec || (rightPrec == parentPrec && (root->val == '-' || root->val == '/'))) {
                rightStr = "(" + rightStr + ")";
            }
        }

        return leftStr + root->val + rightStr;
    }

public:
    string removeBrackets(string Exp) {
        Node* root = buildTree(Exp);
        return stringify(root);
    }
};