#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxCoins(int t, vector<int> &a, vector<int> &b) {
        int n = a.size();
        // Pair structure: {coins_per_plate, available_plates}
        vector<pair<int, int>> boxes(n);
        
        for (int i = 0; i < n; i++) {
            boxes[i] = {b[i], a[i]};
        }
        
        // Sort boxes in descending order based on coins per plate
        sort(boxes.begin(), boxes.end(), [](const pair<int, int> &x, const pair<int, int> &y) {
            return x.first > y.first;
        });
        
        int totalCoins = 0;
        
        for (int i = 0; i < n; i++) {
            if (t <= 0) break; // Thief cannot carry any more plates
            
            int coinsPerPlate = boxes[i].first;
            int availablePlates = boxes[i].second;
            
            // Take either all available plates or as many as the thief can carry
            int platesToTake = min(availablePlates, t);
            
            totalCoins += platesToTake * coinsPerPlate;
            t -= platesToTake; // Reduce the remaining carrying capacity
        }
        
        return totalCoins;
    }
};