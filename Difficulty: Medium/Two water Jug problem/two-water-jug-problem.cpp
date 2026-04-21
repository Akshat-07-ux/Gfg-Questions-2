#include <iostream>
#include <algorithm>

class Solution {
public:
    // Helper function to find GCD
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }

    // Simulates the process from jug 'from' to jug 'to'
    int solve(int fromCap, int toCap, int target) {
        int from = fromCap; // Fill the first jug
        int to = 0;
        int steps = 1; // Initial fill counts as 1 step

        while (from != target && to != target) {
            // Maximum amount that can be poured
            int temp = std::min(from, toCap - to);

            // Pour from 'from' to 'to'
            to += temp;
            from -= temp;
            steps++;

            if (from == target || to == target) break;

            // If first jug becomes empty, fill it
            if (from == 0) {
                from = fromCap;
                steps++;
            }

            // If second jug becomes full, empty it
            if (to == toCap) {
                to = 0;
                steps++;
            }
        }
        return steps;
    }

    int minSteps(int m, int n, int d) {
        // Impossible cases
        if (d > std::max(m, n)) return -1;
        if (d % gcd(m, n) != 0) return -1;

        // Return the minimum steps between the two possible starting directions
        return std::min(solve(m, n, d), solve(n, m, d));
    }
};