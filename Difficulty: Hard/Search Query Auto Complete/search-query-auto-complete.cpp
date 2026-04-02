#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class AutoCompleteSystem {
private:
    struct Node {
        unordered_map<char, Node*> children;
        unordered_map<string, int> counts; // Stores sentence -> frequency
    };

    Node* root;
    Node* currNode;
    string current_query;
    bool dead_end; // Optimization: if prefix doesn't exist, stop searching

    void insert(string sentence, int times) {
        Node* temp = root;
        for (char c : sentence) {
            if (temp->children.find(c) == temp->children.end()) {
                temp->children[c] = new Node();
            }
            temp = temp->children[c];
            temp->counts[sentence] += times;
        }
    }

    struct Compare {
        bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second; // Higher frequency first
            }
            return a.first < b.first; // ASCII smaller first
        }
    };

public:
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new Node();
        currNode = root;
        current_query = "";
        dead_end = false;
        for (int i = 0; i < sentences.size(); i++) {
            insert(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            // End of sentence: save to historical data and reset
            insert(current_query, 1);
            current_query = "";
            currNode = root;
            dead_end = false;
            return {};
        }

        current_query += c;

        // If we already hit a dead end, no need to look further
        if (dead_end || currNode->children.find(c) == currNode->children.end()) {
            dead_end = true;
            return {};
        }

        // Move to the next node in the Trie
        currNode = currNode->children[c];
        
        // Extract all sentences from the current node
        vector<pair<string, int>> candidates;
        for (auto const& [sentence, count] : currNode->counts) {
            candidates.push_back({sentence, count});
        }

        // Sort based on rules
        sort(candidates.begin(), candidates.end(), Compare());

        // Return top 3
        vector<string> result;
        for (int i = 0; i < min(3, (int)candidates.size()); i++) {
            result.push_back(candidates[i].first);
        }

        return result;
    }
};