class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (int num : nums) {
            if (set.find(num) != set.end()) return true;
            set.insert(num);
        }
        return false;
    }
};

// Use a hashset to check for values already visited in array