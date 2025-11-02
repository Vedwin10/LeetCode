class MyHashMap {
public:
    MyHashMap() {
        hashmap_ = vector<int>(1e6+1, -1);
    }
    
    void put(int key, int value) {
        hashmap_[key] = value;
    }
    
    int get(int key) {
        return hashmap_[key];
    }
    
    void remove(int key) {
        hashmap_[key] = -1;
    }
private: 
    vector<int> hashmap_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

// Use a vector<int> of size max_key_value+1, vector[key] for O(1) access
// Use -1 for spaces with no value