class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[j - 1]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

// In-place solution
// We compare 1 element backwards to our current element, and write to index j, where j = i-x, where x is the number of duplicates encounted
