/*
Structure of the node of Huffman tree is as
struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;
};
*/

class Solution {
  public:
    string decodeHuffmanData(struct MinHeapNode* root, string binaryString) {
        string result = "";
        MinHeapNode* curr = root;
        
        for (char bit : binaryString) {
            if (bit == '0') 
                curr = curr->left;
            else 
                curr = curr->right;
            
            // If we reach a leaf node
            if (curr->left == NULL && curr->right == NULL) {
                result.push_back(curr->data);
                curr = root;  // restart for next symbol
            }
        }
        
        return result;
    }
};
