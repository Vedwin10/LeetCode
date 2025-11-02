class HitCounter {
public:
    HitCounter() {}

    /**
     * @param timestamp: the timestamp
     * @return: nothing
     */
    void hit(int timestamp) {
        if (hits_[timestamp] == 0) {
            auto it = hits_.find(timestamp);
            if (it == hits_.begin()) {
                hits_[timestamp] = 1;
            } else {
                --it;
                hits_[timestamp] = it->second + 1;
            }
        } else hits_[timestamp]++;
    }

    /**
     * @param timestamp: the timestamp
     * @return: the count of hits in recent 300 seconds
     */
    int getHits(int timestamp) {
        if (hits_.size() == 0) return 0;
        auto it = hits_.upper_bound(timestamp); --it;
        int res = it->second;
        if (timestamp > 300) {
            auto it2 = hits_.upper_bound(timestamp - 300); --it2;
            if (it2 != hits_.end()) res -= it2->second;
        }
        return res;
    }
private:
    map<int, int> hits_;
};

// We use a map that maps timestamp to all hits that were made up to that second (all-time)
// When adding a hit, if the specific timestamp was never called, we add the map element right before it to its counter, and then add 1
// We use .find(timestamp) to get an iterator to the current element, then do --it to go back one. If .find(timestamp) == begin(), we know there is only 1 element and
// just initialize hits_[timestamp] = 1.
// When calling getHits(), we could call it before any hit was made (if .size() = 0, return 0) or it could be called with a timestamp that wasn't initialized but has values before it
// We know that after the initial check, hits_.size() is >= 1, so we can use upper_bound() to find the first key > timestamp, and do --it to find the first key <= timestamp in hits_
// Now, we simply have to subtract the value of hits_[timestamp - 300] to find the hits within the latest 300 seconds. We can just repeat what we did with timestamp - 300, and 
// if there exists a value <= timestamp - 300 in hits_, we subtract that and return res. For edge cases for that:
// if there is only 1 timestamp in hits_, upper_bound() will return that element, and --it2 will give .end(), so res will stay the same
// if there are 2 timestamps, and the other is > timestamp, the same thing will happen. If the other is < timestamp but > timestamp - 300, the same thing will happen
// if there are 2+ timestamps, and 1 of them is <= timestamp-300, after --it2 we will have access to that key, and res -= it2->second will take care of that accordingly