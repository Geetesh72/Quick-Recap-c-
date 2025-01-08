#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    int capacity;  // Maximum capacity of the cache
    list<pair<int, int>> cache;  // Doubly linked list to store keys and values
    unordered_map<int, list<pair<int, int>>::iterator> hashMap;  // Maps keys to list iterators

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        // If the key exists in the cache
        if (hashMap.find(key) != hashMap.end()) {
            // Move the accessed pair to the front of the list
            auto it = hashMap[key];
            int value = it->second;
            cache.erase(it);
            cache.push_front({key, value});
            hashMap[key] = cache.begin();
            return value;
        }
        return -1;  // Key not found
    }

    void put(int key, int value) {
        // If the key already exists in the cache
        if (hashMap.find(key) != hashMap.end()) {
            auto it = hashMap[key];
            cache.erase(it);  // Remove the existing pair
        } else if (cache.size() >= capacity) {
            // Remove the least recently used element
            auto lru = cache.back();
            hashMap.erase(lru.first);  // Remove it from the map
            cache.pop_back();  // Remove it from the list
        }
        // Insert the new key-value pair at the front of the list
        cache.push_front({key, value});
        hashMap[key] = cache.begin();
    }
};

int main() {
    LRUCache lru(3);  // Create an LRU cache with capacity 3

    lru.put(1, 10);
    lru.put(2, 20);
    lru.put(3, 30);
    cout << lru.get(1) << endl;  // Output: 10
    lru.put(4, 40);  // Evicts key 2
    cout << lru.get(2) << endl;  // Output: -1 (not found)
    lru.put(5, 50);  // Evicts key 3
    cout << lru.get(3) << endl;  // Output: -1 (not found)
    cout << lru.get(4) << endl;  // Output: 40
    cout << lru.get(5) << endl;  // Output: 50

    return 0;
}
