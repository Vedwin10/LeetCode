class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int l = 0, r = 1;
        sort(nums.begin(), nums.end());
        int ret = 0;
        set<pair<int, int>> pairs;
        
        while (r < nums.size()) {
            if (l == r) {
                ++r;
                continue;
            }

            if (abs(nums[r] - nums[l]) == k && pairs.find({nums[l], nums[r]}) == pairs.end()) {
                ++ret;
                int l_val = nums[l];
                int r_val = nums[r];
                while (l < nums.size() && nums[l] == l_val) ++l;
                while (r < nums.size() && nums[r] == r_val) ++r; 
            } else if (abs(nums[r] - nums[l]) < k) {
                ++r;
            } else {
                ++l;
            }
        }

        return ret;
    }
};

// sort first, then two pointers method
// use while to traverse over duplicates