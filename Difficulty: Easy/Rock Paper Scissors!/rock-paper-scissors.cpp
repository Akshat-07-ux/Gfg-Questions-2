#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
private:
    int wins(char m1, char m2) {
        if ((m1 == 'R' && m2 == 'S') || 
            (m1 == 'S' && m2 == 'P') || 
            (m1 == 'P' && m2 == 'R')) {
            return 1;
        }
        return 0;
    }

public:
    vector<int> solveRPS(string a, string b, int k) {
        int n = a.length();
        int m = b.length();

        // LCM of string lengths represents the period of repetition
        long long period = std::lcm((long long)n, (long long)m);
        long long cycleLength = min((long long)k, period);

        long long cycleA = 0, cycleB = 0;
        long long remA = 0, remB = 0;

        long long fullCycles = k / period;
        long long remainder = k % period;

        for (int i = 0; i < cycleLength; ++i) {
            char moveA = a[i % n];
            char moveB = b[i % m];

            int scoreA = wins(moveA, moveB);
            int scoreB = wins(moveB, moveA);

            cycleA += scoreA;
            cycleB += scoreB;

            // Track cumulative scores for the initial remainder steps
            if (i < remainder) {
                remA += scoreA;
                remB += scoreB;
            }
        }

        long long totalA = fullCycles * cycleA + remA;
        long long totalB = fullCycles * cycleB + remB;

        return {(int)totalA, (int)totalB};
    }
};