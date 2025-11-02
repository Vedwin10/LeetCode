class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> unique;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            unique.push_back(nums[i]);
        }
        nums = unique;
        return nums.size();
    }
};

// Iterate over nums, pushing back to a new array, skipping over duplicates
// Set nums = new_array