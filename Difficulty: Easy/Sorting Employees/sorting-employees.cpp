class Solution {
  public:
    vector<string> sortRecords(vector<string>& employee, vector<int>& salary) {
        int n = employee.size();
        vector<pair<int, string>> records;

        // Pair salary with employee name
        for (int i = 0; i < n; i++) {
            records.push_back({salary[i], employee[i]});
        }

        // Sort by salary, then by name
        sort(records.begin(), records.end(), [](auto &a, auto &b) {
            if (a.first == b.first)
                return a.second < b.second; // alphabetical order
            return a.first < b.first;       // salary order
        });

        // Extract sorted employee names
        vector<string> result;
        for (auto &rec : records) {
            result.push_back(rec.second);
        }

        return result;
    }
};
