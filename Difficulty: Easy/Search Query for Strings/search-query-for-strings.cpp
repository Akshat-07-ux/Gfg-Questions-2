/*
// Standard Structure of TrieNode (for reference)
struct TrieNode {
    struct TrieNode *children[26];
    bool isEndOfWord;
};
*/

// Function to insert string into TRIE.
void insert(struct TrieNode *root, string key) {
    struct TrieNode *curr = root;
    
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a'; // Get index (0-25) for the character
        
        // If the path for this character doesn't exist, create a new node
        if (curr->children[index] == NULL) {
            curr->children[index] = new TrieNode();
        }
        
        // Move to the child node
        curr = curr->children[index];
    }
    
    // Mark the last node as the end of the word
    curr->isEndOfWord = true;
}

// Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) {
    struct TrieNode *curr = root;
    
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        
        // If any character in the key is not found, return false
        if (curr->children[index] == NULL) {
            return false;
        }
        
        curr = curr->children[index];
    }
    
    // Return true if the string ends at a node marked as end of word
    return (curr != NULL && curr->isEndOfWord);
}