#include <bits/stdc++.h>
using namespace std;

int stringComparison(string s1, string s2) {
    // Define the priority order (special handling for "ng")
    unordered_map<string, int> order;
    string chars[] = {
        "a","b","c","d","e","f","g","h","i","j","k",
        "l","m","n","ng","o","p","q","r","s","t",
        "u","v","w","x","y","z"
    };
    
    for (int i = 0; i < 26 + 1; i++) { // 27 symbols including "ng"
        order[chars[i]] = i;
    }

    int i = 0, j = 0;
    int n1 = s1.size(), n2 = s2.size();

    while (i < n1 && j < n2) {
        string ch1, ch2;

        // Handle special "ng"
        if (s1[i] == 'n' && i + 1 < n1 && s1[i + 1] == 'g') {
            ch1 = "ng";
            i += 2;
        } else {
            ch1 = string(1, s1[i]);
            i++;
        }

        if (s2[j] == 'n' && j + 1 < n2 && s2[j + 1] == 'g') {
            ch2 = "ng";
            j += 2;
        } else {
            ch2 = string(1, s2[j]);
            j++;
        }

        // Compare based on priority
        if (order[ch1] < order[ch2]) return -1;
        if (order[ch1] > order[ch2]) return 1;
    }

    // If one string is longer than the other
    if (i < n1) return 1;
    if (j < n2) return -1;
    return 0;
}


