#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findSurpasser(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, 0);

        // pair of (value, original_index)
        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++) {
            vec.push_back({arr[i], i});
        }

        mergeSort(vec, 0, n-1, result);
        return result;
    }

  private:
    void mergeSort(vector<pair<int,int>>& vec, int left, int right, vector<int>& result) {
        if(left >= right) return;
        int mid = (left + right) / 2;
        mergeSort(vec, left, mid, result);
        mergeSort(vec, mid+1, right, result);
        merge(vec, left, mid, right, result);
    }

    void merge(vector<pair<int,int>>& vec, int left, int mid, int right, vector<int>& result) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<pair<int,int>> L(vec.begin()+left, vec.begin()+mid+1);
        vector<pair<int,int>> R(vec.begin()+mid+1, vec.begin()+right+1);

        int i=0, j=0, k=left;
        while(i<n1 && j<n2) {
            if(L[i].first < R[j].first) {
                // R[j] is greater and to the right → so all remaining in R are surpassers for L[i]
                result[L[i].second] += (n2 - j);
                vec[k++] = L[i++];
            } else {
                vec[k++] = R[j++];
            }
        }
        while(i<n1) vec[k++] = L[i++];
        while(j<n2) vec[k++] = R[j++];
    }
};
