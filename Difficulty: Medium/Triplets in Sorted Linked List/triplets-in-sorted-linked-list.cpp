class Solution {
  public:
    int countTriplets(Node* head, int x) {
        vector<int> arr;

        while (head) {
            arr.push_back(head->data);
            head = head->next;
        }

        reverse(arr.begin(), arr.end()); // ascending order

        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = arr[i] + arr[l] + arr[r];

                if (sum == x) {
                    count++;
                    l++;
                    r--;
                }
                else if (sum < x) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }

        return count;
    }
};