#include<bits/stdc++.h>


class LRUCache {
public:
    int c, cap, count;
    unordered_map<int, pair<int, int>> cache;

    LRUCache(int capacity) {
        cap = capacity;
        count = 0;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            updateLRU(key);
            return cache[key].first;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            updateLRU(key);
            cache[key].first = value;
        } else {
            if (cache.size() == cap) {
                int lruKey = findLRUKey();
                cache.erase(lruKey);
            }
            cache[key] = { value, count };
            count++;
        }
    }

    void updateLRU(int key) {
        cache[key].second = count;
        count++;
    }

    int findLRUKey() {
        int lruKey = -1;
        int minCount = INT_MAX;
        for (const auto& kvp : cache) {
            if (kvp.second.second < minCount) {
                lruKey = kvp.first;
                minCount = kvp.second.second;
            }
        }
        return lruKey;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
