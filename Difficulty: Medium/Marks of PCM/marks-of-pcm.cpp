#include <vector>
#include <algorithm>

// Define a structure to hold the marks of a student
struct Student {
    int phy;
    int chem;
    int math;
};

class Solution {
  public:
    // Custom comparator to sort according to the rules
    static bool compareStudents(const Student& a, const Student& b) {
        // Rule 1: Sort by Physics marks in ascending order
        if (a.phy != b.phy) {
            return a.phy < b.phy;
        }
        
        // Rule 2: If Physics marks are equal, sort by Chemistry in descending order
        if (a.chem != b.chem) {
            return a.chem > b.chem;
        }
        
        // Rule 3: If both are equal, sort by Math in ascending order
        return a.math < b.math;
    }

    void customSort(int phy[], int chem[], int math[], int N) {
        // Step 1: Combine the separate arrays into a single vector of structures
        std::vector<Student> students(N);
        for (int i = 0; i < N; i++) {
            students[i] = {phy[i], chem[i], math[i]};
        }
        
        // Step 2: Sort using our custom comparator
        std::sort(students.begin(), students.end(), compareStudents);
        
        // Step 3: Write the sorted results back into the original arrays
        for (int i = 0; i < N; i++) {
            phy[i] = students[i].phy;
            chem[i] = students[i].chem;
            math[i] = students[i].math;
        }
    }
};