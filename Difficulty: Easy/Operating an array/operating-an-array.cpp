#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    // Function to search for element x in the array
    bool searchEle(vector<int>& arr, int x) {
        // Use std::find to look for x
        return find(arr.begin(), arr.end(), x) != arr.end();
    }

    // Function to insert element y at index yi
    void insertEle(vector<int>& arr, int y, int yi) {
        // Ensure index is within valid bounds for insertion
        if (yi >= 0 && yi <= arr.size()) {
            arr.insert(arr.begin() + yi, y);
        }
    }

    // Function to delete the first occurrence of element z
    void deleteEle(vector<int>& arr, int z) {
        // Find the first occurrence of z
        auto it = find(arr.begin(), arr.end(), z);
        
        // If element is found, erase it
        if (it != arr.end()) {
            arr.erase(it);
        }
    }
};