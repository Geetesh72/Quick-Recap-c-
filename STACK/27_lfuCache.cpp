#include <bits/stdc++.h>
using namespace std;

class LFUCache {
private:
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyToValueFreq;  // key -> {value, freq}
    unordered_map<int, list<int>> freqToKeys;          // freq -> list of keys
    unordered_map<int, list<int>::iterator> keyToIter; // key -> iterator of its position in freqToKeys

    void updateFrequency(int key) {
        // Get the frequency of the key
        int freq = keyToValueFreq[key].second;
        // Remove the key from its current frequency list
        freqToKeys[freq].erase(keyToIter[key]);
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq) {
                minFreq++;  // Update minFreq if the current frequency list becomes empty
            }
        }
        // Increase the frequency of the key
        freq++;
        keyToValueFreq[key].second = freq;
        freqToKeys[freq].push_front(key);  // Add the key to the new frequency list
        keyToIter[key] = freqToKeys[freq].begin();  // Update iterator
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (keyToValueFreq.find(key) == keyToValueFreq.end()) {
            return -1;  // Key not found
        }
        updateFrequency(key);  // Update the frequency of the key
        return keyToValueFreq[key].first;  // Return the value
    }

    void put(int key, int value) {
        if (capacity == 0) return;  // If cache capacity is 0, do nothing

        if (keyToValueFreq.find(key) != keyToValueFreq.end()) {
            // If key exists, update its value and frequency
            keyToValueFreq[key].first = value;
            updateFrequency(key);
            return;
        }

        if (keyToValueFreq.size() >= capacity) {
            // Evict the least frequently used key
            int evictKey = freqToKeys[minFreq].back();  // Get the LRU key in the minimum frequency list
            freqToKeys[minFreq].pop_back();  // Remove it from the frequency list
            if (freqToKeys[minFreq].empty()) {
                freqToKeys.erase(minFreq);  // Remove the frequency list if empty
            }
            keyToValueFreq.erase(evictKey);  // Remove from key-value map
            keyToIter.erase(evictKey);  // Remove from iterator map
        }

        // Add the new key-value pair
        keyToValueFreq[key] = {value, 1};  // Value with frequency 1
        freqToKeys[1].push_front(key);  // Add to frequency 1 list
        keyToIter[key] = freqToKeys[1].begin();  // Store iterator
        minFreq = 1;  // Reset minFreq to 1 for the new key
    }
};

int main() {
    LFUCache lfu(2);  // Create LFU cache with capacity 2

    lfu.put(1, 10);
    lfu.put(2, 20);
    cout << lfu.get(1) << endl;  // Output: 10
    lfu.put(3, 30);  // Evicts key 2 (least frequently used)
    cout << lfu.get(2) << endl;  // Output: -1 (not found)
    cout << lfu.get(3) << endl;  // Output: 30
    lfu.put(4, 40);  // Evicts key 1 (least frequently used)
    cout << lfu.get(1) << endl;  // Output: -1 (not found)
    cout << lfu.get(3) << endl;  // Output: 30
    cout << lfu.get(4) << endl;  // Output: 40

    return 0;
}
