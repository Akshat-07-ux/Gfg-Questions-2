class Solution {
public:
    bool isPossible(long long mid, int k, vector<int>& arr) {
        long long total_slots_filled = 0;
        long long required_slots = mid * k;

        for (int players : arr) {
            // A country can contribute at most 1 player per team
            total_slots_filled += min((long long)players, mid);
        }

        return total_slots_filled >= required_slots;
    }

    int countOfTeams(int k, vector<int>& arr) {
        long long low = 0;
        long long high = 0;
        for (int x : arr) high += x;
        high /= k; // Theoretical maximum possible teams

        int result = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid == 0) {
                low = mid + 1;
                continue;
            }

            if (isPossible(mid, k, arr)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};