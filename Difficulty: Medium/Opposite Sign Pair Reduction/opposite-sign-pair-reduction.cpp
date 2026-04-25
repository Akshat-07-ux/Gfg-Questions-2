class Solution {
public:
    vector<int> reducePairs(vector<int>& arr) {
        vector<int> st; // Using a vector as a stack for easy return

        for (int current : arr) {
            bool destroyed = false;

            // While stack is not empty and signs are opposite
            while (!st.empty() && ((st.back() > 0 && current < 0) || (st.back() < 0 && current > 0))) {
                int top = st.back();
                
                if (abs(top) > abs(current)) {
                    // Current element is destroyed, stack element stays
                    destroyed = true;
                    break;
                } else if (abs(top) < abs(current)) {
                    // Stack element is destroyed, current continues to check next stack element
                    st.pop_back();
                    continue;
                } else {
                    // Both are equal in absolute value, both destroyed
                    st.pop_back();
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push_back(current);
            }
        }

        return st;
    }
};