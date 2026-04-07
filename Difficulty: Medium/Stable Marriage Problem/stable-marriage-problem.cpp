#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();

        // woman_partner[i] stores the man currently engaged to woman i. 
        // Initialized to -1 (free).
        vector<int> woman_partner(n, -1);

        // man_partner[i] stores the woman currently engaged to man i.
        vector<int> man_partner(n, -1);

        // next_proposal[i] stores the index of the next woman in men[i] to propose to.
        vector<int> next_proposal(n, 0);

        // Precompute woman's preferences for O(1) comparison.
        // rank[w][m] = the rank of man m in woman w's preference list.
        vector<vector<int>> rank(n, vector<int>(n));
        for (int w = 0; w < n; ++w) {
            for (int r = 0; r < n; ++r) {
                rank[w][women[w][r]] = r;
            }
        }

        // Queue of free men.
        queue<int> free_men;
        for (int i = 0; i < n; ++i) {
            free_men.push(i);
        }

        while (!free_men.empty()) {
            int m = free_men.front();
            
            // Get the man's top choice woman he hasn't proposed to yet
            int w = men[m][next_proposal[m]++];
            
            if (woman_partner[w] == -1) {
                // Woman is free, they get engaged
                woman_partner[w] = m;
                man_partner[m] = w;
                free_men.pop();
            } else {
                // Woman is already engaged, check her preference
                int current_m = woman_partner[w];
                
                if (rank[w][m] < rank[w][current_m]) {
                    // She prefers the new man over her current partner
                    woman_partner[w] = m;
                    man_partner[m] = w;
                    
                    // The old partner is now free
                    man_partner[current_m] = -1;
                    free_men.pop();
                    free_men.push(current_m);
                } else {
                    // She rejects the man; he stays in the queue to propose to his next choice
                    // (The pop/push logic isn't strictly needed if we just leave him at the front)
                }
            }
        }

        return man_partner;
    }
};