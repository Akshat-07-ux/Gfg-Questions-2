class Solution {
public:
    int maxArea(vector<vector<int>> &mat) {
        if (mat.empty() || mat[0].empty()) return 0;
        
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;
        
        for (int i = 0; i < rows; i++) {
            // Update heights for current row
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1) {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            
            // Find largest rectangle in current histogram
            maxArea = max(maxArea, largestRectangleInHistogram(heights));
        }
        
        return maxArea;
    }
    
private:
    int largestRectangleInHistogram(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && heights[st.top()] > currentHeight) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            
            st.push(i);
        }
        
        return maxArea;
    }
};