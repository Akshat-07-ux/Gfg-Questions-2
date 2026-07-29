class Solution {
public:
    vector<int> sortArray(vector<int>& arr) {
        int n = arr.size();

        int i = 0;
        while (i < n) {
            if (arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            } else {
                i++;
            }
        }

        return arr;
    }
};