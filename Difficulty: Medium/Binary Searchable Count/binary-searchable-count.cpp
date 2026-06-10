class Solution {
  public:
    int binarySearchable(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        function<void(int, int, long long, long long)> dfs =
            [&](int l, int r, long long lb, long long ub) {
                if (l > r) return;

                int mid = (l + r) / 2;

                if (arr[mid] > lb && arr[mid] < ub)
                    ans++;

                dfs(l, mid - 1, lb, min(ub, (long long)arr[mid]));
                dfs(mid + 1, r, max(lb, (long long)arr[mid]), ub);
            };

        dfs(0, n - 1, LLONG_MIN, LLONG_MAX);
        return ans;
    }
};