class MyHashSet {
public:
    MyHashSet() {
        hashset_ = vector<bool>(1e6+1, false);
    }
    
    void add(int key) {
        hashset_[key] = true;
    }
    
    void remove(int key) {
        hashset_[key] = false;
    }
    
    bool contains(int key) {
        return hashset_[key] == true;
    }
private:
    vector<bool> hashset_;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

// Vector of max key size, O(1) access with vector[key]
// No values stored, so we can use a vector<bool>
