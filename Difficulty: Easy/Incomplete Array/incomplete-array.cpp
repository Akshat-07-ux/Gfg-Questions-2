class Solution {
  public:
    int countElements(vector<int> &arr) {
        if (arr.size() <= 1) return 0;

        int mn = *min_element(arr.begin(), arr.end());
        int mx = *max_element(arr.begin(), arr.end());

        unordered_set<int> st(arr.begin(), arr.end());

        int totalNeeded = mx - mn + 1;
        int alreadyPresent = st.size();

        return totalNeeded - alreadyPresent;
    }
};
