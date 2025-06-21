class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        int result = 0;

        queue<int> police, thief;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P') {
                police.push(i);
            } else if (arr[i] == 'T') {
                thief.push(i);
            }

            // Match the earliest police and thief who are within distance k
            while (!police.empty() && !thief.empty()) {
                if (abs(police.front() - thief.front()) <= k) {
                    result++;
                    police.pop();
                    thief.pop();
                }
                else if (thief.front() < police.front()) {
                    thief.pop();
                }
                else {
                    police.pop();
                }
            }
        }
        return result;
    }
};