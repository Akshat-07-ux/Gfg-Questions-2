/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;  // min-heap
        }
    };
    
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, compare> pq;
        
        // Step 1: Push head of each list into the heap
        for (auto listHead : arr) {
            if (listHead != NULL) {
                pq.push(listHead);
            }
        }
        
        // Dummy node to simplify handling
        Node* dummy = new Node(0);
        Node* tail = dummy;
        
        // Step 2: Extract min, move forward, push next nodes
        while (!pq.empty()) {
            Node* top = pq.top();
            pq.pop();
            
            tail->next = top;
            tail = tail->next;
            
            if (top->next != NULL) {
                pq.push(top->next);
            }
        }
        
        Node* result = dummy->next;
        delete dummy; // free dummy node
        return result;
    }
};
