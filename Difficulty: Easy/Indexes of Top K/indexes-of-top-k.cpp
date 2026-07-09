#include <vector>
#include <algorithm>
#include <set>

class Solution {
  public:
    std::vector<int> topKIndices(std::vector<int> &arr, int k) {
        int n = arr.size();
        
        // Find all unique marks using a set (automatically sorted in ascending order)
        std::set<int> uniqueMarks(arr.begin(), arr.end());
        
        // Convert to a vector to easily access by index from the top
        std::vector<int> sortedUnique(uniqueMarks.begin(), uniqueMarks.end());
        std::reverse(sortedUnique.begin(), sortedUnique.end()); // Descending order
        
        // Find the cutoff mark (the k-th distinct mark)
        // If k is greater than total distinct marks, use the lowest available distinct mark
        int cutoffIndex = std::min(k, (int)sortedUnique.size()) - 1;
        int cutoffMark = sortedUnique[cutoffIndex];
        
        // Pair structure: {marks, index}
        std::vector<std::pair<int, int>> validStudents;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= cutoffMark) {
                validStudents.push_back({arr[i], i});
            }
        }
        
        // Sort the qualifying students
        std::sort(validStudents.begin(), validStudents.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first; // Descending order of marks
            }
            return a.second < b.second;   // Ascending order of indices if marks are equal
        });
        
        // Extract the sorted indices
        std::vector<int> result(validStudents.size());
        for (size_t i = 0; i < validStudents.size(); i++) {
            result[i] = validStudents[i].second;
        }
        
        return result;
    }
};