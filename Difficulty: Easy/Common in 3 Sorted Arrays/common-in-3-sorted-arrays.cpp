class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        vector<int> result;
        int i = 0, j = 0, k = 0;
        int n1 = a.size(), n2 = b.size(), n3 = c.size();

        while (i < n1 && j < n2 && k < n3) {
            // Found a common element
            if (a[i] == b[j] && b[j] == c[k]) {
                // Add to result if it's the first element or not a duplicate
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++;
                j++;
                k++;
            }
            // If a[i] is the smallest, it can't be common unless we move forward
            else if (a[i] < b[j]) {
                i++;
            }
            // If b[j] is the smallest
            else if (b[j] < c[k]) {
                j++;
            }
            // If c[k] is the smallest
            else {
                k++;
            }
        }
        return result;
    }
};