class Solution {
  public:
    unordered_map<string, int> subtreeMap;
    int duplicateCount = 0;
    
    string serialize(Node* root) {
        if (!root) return "";
        
        string serial = to_string(root->data);  // use 'data' not 'key'
        vector<string> childSerials;
        
        for (auto child : root->children) {
            childSerials.push_back(serialize(child));
        }

        

        for (const string& s : childSerials) {
            serial += "(" + s + ")";
        }
        
        if (++subtreeMap[serial] == 2) {
            duplicateCount++;
        }
        
        return serial;
    }
    
    int duplicateSubtreeNaryTree(Node *root) {
        subtreeMap.clear();
        duplicateCount = 0;
        serialize(root);
        return duplicateCount;
    }
};
