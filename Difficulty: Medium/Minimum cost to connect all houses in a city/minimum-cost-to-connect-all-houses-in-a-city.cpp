#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        if (n == 0) return 0;

        int totalCost = 0;
        int edgesConnected = 0;
        
        // track if house i is already included in the MST
        vector<bool> inMST(n, false);
        
        // minDist[i] stores the minimum cost to connect house i to the existing MST
        vector<int> minDist(n, INT_MAX);
        
        // Start with the first house
        minDist[0] = 0;

        while (edgesConnected < n) {
            int currHouse = -1;
            int currMinDist = INT_MAX;

            // Greedily pick the house with the smallest distance to the current MST
            for (int i = 0; i < n; ++i) {
                if (!inMST[i] && minDist[i] < currMinDist) {
                    currMinDist = minDist[i];
                    currHouse = i;
                }
            }

            // Add the chosen house to MST
            inMST[currHouse] = true;
            totalCost += currMinDist;
            edgesConnected++;

            // Update distances to all other houses not yet in MST
            for (int nextHouse = 0; nextHouse < n; ++nextHouse) {
                if (!inMST[nextHouse]) {
                    int dist = abs(houses[currHouse][0] - houses[nextHouse][0]) + 
                               abs(houses[currHouse][1] - houses[nextHouse][1]);
                    
                    if (dist < minDist[nextHouse]) {
                        minDist[nextHouse] = dist;
                    }
                }
            }
        }

        return totalCost;
    }
};