class SnapshotArray {
private:
    vector<map<int, int>> arr_;    
    int snap_id_ = 0;
public:
    SnapshotArray(int length) {
        arr_ = vector<map<int, int>>(length, map<int,int>());
    }
    
    void set(int index, int val) {
        arr_[index][snap_id_] = val;
    }
    
    int snap() {
        return snap_id_++;
    }
    
    int get(int index, int snap_id) {
        auto it = arr_[index].upper_bound(snap_id);
        if (it == arr_[index].begin()) return 0;
        --it; return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

// Basically, only change your data structure every time there is a change, to avoid excessive space usage
// Use a vector of maps that maps each index to a map of the history of its changes, snap_id : value
// Use .upper_bound and --it to find the key <= snap_id
// This solution is faster because it initializes map without 0s, and just returns 0 if it == begin() in get()
