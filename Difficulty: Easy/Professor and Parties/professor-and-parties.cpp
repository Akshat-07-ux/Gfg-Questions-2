class Solution {
  public:
    string PartyType(vector<int>& arr) {
        unordered_set<int> seen;

        for (int color : arr) {
            // If color already exists, it's a BOYS party
            if (seen.count(color)) {
                return "true";
            }
            seen.insert(color);
        }

        // All colors are unique -> GIRLS party
        return "false";
    }
};
