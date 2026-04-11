#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false) {}
};

class Solution {
public:
    void check(string *arr, int n) {
        TrieNode* root = new TrieNode();
        unordered_map<string, int> cityCount;

        for (int i = 0; i < n; i++) {
            string s = arr[i];
            cityCount[s]++;
            
            // If the city has appeared before, use the "name count" format
            if (cityCount[s] > 1) {
                cout << s << " " << cityCount[s] << endl;
                // Still insert/traverse to keep the Trie updated for future prefixes
                insert(root, s);
            } else {
                // If it's a new city, find the shortest unique prefix
                cout << getShortestPrefix(root, s) << endl;
            }
        }
    }

private:
    void insert(TrieNode* root, string s) {
        TrieNode* curr = root;
        for (char c : s) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }

    string getShortestPrefix(TrieNode* root, string s) {
        TrieNode* curr = root;
        string prefix = "";
        bool foundUnique = false;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            prefix += c;
            if (!foundUnique && curr->children.find(c) == curr->children.end()) {
                // This is the first time this path is taken
                // Create the rest of the path and return the current prefix
                curr->children[c] = new TrieNode();
                curr = curr->children[c];
                foundUnique = true;
                // Continue insertion of the rest of the string
                for (int j = i + 1; j < s.length(); j++) {
                    curr->children[s[j]] = new TrieNode();
                    curr = curr->children[s[j]];
                }
                curr->isEndOfWord = true;
                return prefix;
            }
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
        return prefix; // If no unique prefix is found, return the whole name
    }
};