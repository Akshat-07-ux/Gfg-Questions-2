#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

// Global boolean array for primes to allow precomputation
bool isPrime[10000];

class Solution {
public:
    // Constructor to precompute primes using Sieve of Eratosthenes
    Solution() {
        for (int i = 0; i < 10000; i++) isPrime[i] = true;
        isPrime[0] = isPrime[1] = false;
        for (int p = 2; p * p <= 9999; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= 9999; i += p)
                    isPrime[i] = false;
            }
        }
    }

    int shortestPath(int Num1, int Num2) {
        if (Num1 == Num2) return 0;

        // dist array to store steps and act as a visited set
        // Initializing with -1
        vector<int> dist(10000, -1);
        queue<int> q;

        q.push(Num1);
        dist[Num1] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            string s = to_string(curr);

            // Try changing each of the 4 positions
            for (int i = 0; i < 4; i++) {
                char originalChar = s[i];
                
                for (char ch = '0'; ch <= '9'; ch++) {
                    if (ch == originalChar) continue;
                    
                    // No leading zeros for 4-digit numbers
                    if (i == 0 && ch == '0') continue;

                    s[i] = ch;
                    int nextNum = stoi(s);

                    // If it's prime and not visited
                    if (isPrime[nextNum] && dist[nextNum] == -1) {
                        dist[nextNum] = dist[curr] + 1;
                        if (nextNum == Num2) return dist[nextNum];
                        q.push(nextNum);
                    }
                }
                // Backtrack to original string for next position
                s[i] = originalChar;
            }
        }

        return -1; // Unreachable
    }
};