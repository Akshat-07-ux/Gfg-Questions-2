#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countRevPairs(vector<int> &arr) {
        return mergeSortCount(arr, 0, arr.size() - 1);
    }

  private:
    int mergeSortCount(vector<int> &arr, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        int count = 0;

        count += mergeSortCount(arr, left, mid);
        count += mergeSortCount(arr, mid + 1, right);
        count += countCrossPairs(arr, left, mid, right);

        merge(arr, left, mid, right);
        return count;
    }

    int countCrossPairs(vector<int> &arr, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        return count;
    }

    void merge(vector<int> &arr, int left, int mid, int right) {
        vector<int> temp;
        int i = left, j = mid + 1;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }

        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);

        for (int k = left; k <= right; k++) {
            arr[k] = temp[k - left];
        }
    }
};


