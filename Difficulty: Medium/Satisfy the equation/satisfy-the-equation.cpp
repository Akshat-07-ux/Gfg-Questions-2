#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        unordered_map<int, pair<int, int>> sumMap;
        vector<int> result(4, -1);
        bool found = false;

        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int sum = A[i] + A[j];

                if (sumMap.find(sum) != sumMap.end()) {
                    auto p = sumMap[sum];
                    int a = p.first, b = p.second;

                    // Ensure all indices are distinct
                    if (a != i && a != j && b != i && b != j) {
                        vector<int> candidate = {a, b, i, j};
                        if (!found || candidate < result) {
                            result = candidate;
                            found = true;
                        }
                    }
                } else {
                    sumMap[sum] = {i, j};
                }
            }
        }

        return result;
    }
};
