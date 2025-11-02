class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int j = 2;
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] != nums[j - 2]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

// This changes the array in-place by having a "write" index
// Our write index starts at the same place as the original index's start (i = 2, because first 2 elements guaranteed okay), but we compare with j - 2
// It's kind of like a sliding window, where we're comparing the element at j-2 to the current element, and writing to our index j (could be same or different than i)
