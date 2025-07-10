class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class Solution {
public:
    string longestString(vector<string>& words) {
        // Sort to ensure lexicographical order is maintained
        sort(words.begin(), words.end());

        TrieNode* root = new TrieNode();
        string result = "";

        for (const string& word : words) {
            if (insert(root, word)) {
                if (word.length() > result.length()) {
                    result = word;
                }
            }
        }

        return result;
    }

private:
    bool insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        bool valid = true;

        for (int i = 0; i < word.size(); ++i) {
            int idx = word[i] - 'a';

            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];

            // Check if prefix exists
            if (i < word.size() - 1 && !node->isEnd) {
                valid = false;
            }
        }

        node->isEnd = true;
        return valid;
    }
};
