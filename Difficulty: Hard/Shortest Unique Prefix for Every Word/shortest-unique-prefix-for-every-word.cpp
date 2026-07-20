#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        int freq;
        
        TrieNode() {
            freq = 0;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    // Insert a string into the Trie and increment the frequency of visited nodes
    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
            curr->freq++; // Track how many words share this prefix path
        }
    }
    
    // Find the shortest unique prefix for a given string
    string getUniquePrefix(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        string prefix = "";
        
        for (char ch : word) {
            prefix += ch;
            int index = ch - 'a';
            curr = curr->children[index];
            
            // The moment frequency becomes 1, this prefix is unique
            if (curr->freq == 1) {
                return prefix;
            }
        }
        return prefix;
    }
    
    // Helper to avoid memory leaks
    void clear(TrieNode* root) {
        if (!root) return;
        for (int i = 0; i < 26; i++) {
            if (root->children[i]) {
                clear(root->children[i]);
            }
        }
        delete root;
    }

public:
    vector<string> findPrefixes(vector<string>& arr) {
        TrieNode* root = new TrieNode();
        
        // Step 1: Build the Trie
        for (const string& word : arr) {
            insert(root, word);
        }
        
        // Step 2: Find the unique prefix for each word
        vector<string> result;
        for (const string& word : arr) {
            result.push_back(getUniquePrefix(root, word));
        }
        
        // Step 3: Clean up memory
        clear(root);
        
        return result;
    }
};