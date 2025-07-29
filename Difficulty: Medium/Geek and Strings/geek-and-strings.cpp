#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    int prefixCount;

    TrieNode() {
        prefixCount = 0;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
            node->prefixCount++;  // Increment for each prefix node
        }
    }

    int countPrefix(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx])
                return 0;  // Prefix doesn't exist
            node = node->children[idx];
        }
        return node->prefixCount;
    }
};

class Solution {
  public:
    vector<int> prefixCount(int N, int Q, string li[], string query[]) {
        Trie trie;

        // Insert all words into Trie
        for (int i = 0; i < N; ++i)
            trie.insert(li[i]);

        // Process each query
        vector<int> result;
        for (int i = 0; i < Q; ++i) {
            result.push_back(trie.countPrefix(query[i]));
        }

        return result;
    }
};
