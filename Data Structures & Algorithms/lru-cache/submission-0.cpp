class LRUCache {
private:
    int capacity;
    list<pair<int,int>> dll; // {key, value} doubly linked list
    unordered_map<int, list<pair<int,int>>::iterator> mp; // key -> node in list

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        // move the accessed node to the front
        auto it = mp[key];
        int val = it->second;
        dll.erase(it);
        dll.push_front({key, val});
        mp[key] = dll.begin();
        return val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // erase old node
            dll.erase(mp[key]);
        } else if (dll.size() == capacity) {
            // remove LRU (last element in list)
            auto lru = dll.back();
            mp.erase(lru.first);
            dll.pop_back();
        }
        // insert new node at front
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};
