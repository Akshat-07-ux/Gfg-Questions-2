class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        vector<int> police, thief;

        // Store indices of police and thieves
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P')
                police.push_back(i);
            else
                thief.push_back(i);
        }

        int i = 0, j = 0, caught = 0;

        // Two pointer approach
        while (i < police.size() && j < thief.size()) {
            if (abs(police[i] - thief[j]) <= k) {
                caught++;
                i++;
                j++;
            }
            else if (thief[j] < police[i]) {
                j++;
            }
            else {
                i++;
            }
        }

        return caught;
    }
};
