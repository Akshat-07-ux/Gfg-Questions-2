#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Helper function to handle the recursive post-order printing
void solve(vector<int>& pre, int preStart, int preEnd, 
           int inStart, int inEnd, unordered_map<int, int>& inMap) {
    
    // Base case: if there are no elements to process
    if (preStart > preEnd || inStart > inEnd) return;

    // The first element in pre-order is the root of the current subtree
    int rootVal = pre[preStart];
    int rootIdx = inMap[rootVal]; // Find root index in In-order
    
    // Calculate the number of nodes in the left subtree
    int leftSize = rootIdx - inStart;

    // 1. Recurse for the Left subtree
    solve(pre, preStart + 1, preStart + leftSize, inStart, rootIdx - 1, inMap);

    // 2. Recurse for the Right subtree
    solve(pre, preStart + leftSize + 1, preEnd, rootIdx + 1, inEnd, inMap);

    // 3. Print the Root (Post-order: Left, Right, Root)
    cout << rootVal << " ";
}

void printPostOrder(vector<int>& in, vector<int>& pre) {
    int n = in.size();
    if (n == 0) return;

    // Map to store value -> index for O(1) lookup in In-order array
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; i++) {
        inMap[in[i]] = i;
    }

    solve(pre, 0, n - 1, 0, n - 1, inMap);
}