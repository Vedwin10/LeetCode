class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixes(nums.size(), 1);
        vector<int> suffixes(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            prefixes[i] = nums[i-1] * prefixes[i-1];
        }
        for (int i = nums.size() - 2; i >= 0; --i) {
            suffixes[i] = nums[i+1] * suffixes[i+1];
        }

        vector<int> ret(nums.size());
        for (int i = 0; i < ret.size(); ++i) {
            ret[i] = prefixes[i] * suffixes[i];
        }
        return ret;
    }
};

// use prefixes and suffixes method, dynamic programming
