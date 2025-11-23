class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            sum %= k;
            if (sum == 0 && i > 0) return true;
            if (mp.find(sum) != mp.end() && i - mp[sum] > 1) return true;
            if (mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return false;
    }
};

// have a running prefix_sum % k
// if you've found that sum % k before, that means you have to have had some sequence of numbers that brought the mod back to its original value
// that sequence of numbers % k = 0, so you've found your answer
// like if my prefix_sum % k array was : [5, 1, 3, 4, 5] that means from i=0 to i=4, the sequence has a sum % k == 0.
// we must also consider some edge cases like [1, 0] k = 2, [5, 0, 0, 0], or where the prefix_sum % k == 0 itself
// for that, we track index. if the sum was found, it must be a distance of 2 or more away from the last time it happened
// two 0's in a row is a valid subarray size 2 where 0+0 = 0, and there exists an integer n such that 0 = nk (just 0), so that case is valid
// if the prefix sum % k is 0, just make sure it's not the first element (must be subarray size >= 2)
