#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

struct Node {
    int key, value, freq;
    Node(int k, int v, int f) : key(k), value(v), freq(f) {}
};

class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int, list<Node>::iterator> keyNode; // key -> iterator in freqList
    unordered_map<int, list<Node>> freqList;         // freq -> list of Nodes

    void updateFrequency(int key) {
        auto it = keyNode[key];
        int f = it->freq;
        int v = it->value;
        
        // Remove from current frequency list
        freqList[f].erase(it);
        if (freqList[f].empty()) {
            freqList.erase(f);
            if (minFreq == f) minFreq++;
        }
        
        // Insert into new frequency list (f + 1)
        freqList[f + 1].push_front(Node(key, v, f + 1));
        keyNode[key] = freqList[f + 1].begin();
    }

public:
    LFUCache(int cap) {
        capacity = cap;
        minFreq = 0;
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) return -1;
        
        int val = keyNode[key]->value;
        updateFrequency(key);
        return val;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;

        // If key exists, update value and frequency
        if (keyNode.find(key) != keyNode.end()) {
            keyNode[key]->value = value;
            updateFrequency(key);
            return;
        }

        // If capacity is full, evict LFU (and LRU in case of tie)
        if (keyNode.size() >= capacity) {
            int keyToEvict = freqList[minFreq].back().key;
            keyNode.erase(keyToEvict);
            freqList[minFreq].pop_back();
            if (freqList[minFreq].empty()) freqList.erase(minFreq);
        }

        // Insert new element
        minFreq = 1;
        freqList[minFreq].push_front(Node(key, value, 1));
        keyNode[key] = freqList[minFreq].begin();
    }
};