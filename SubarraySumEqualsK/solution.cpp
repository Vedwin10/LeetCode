class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0, res = 0;
        mp[0] = 1;
        for (int num : nums) {
            sum += num;
            if (mp.find(sum - k) != mp.end()) res += mp[sum-k];
            mp[sum]++;
        }
        return res;
    }
};

// Use nums array to create prefix_sums array, which is an array of the sums leading up to nums[i]. So nums[0] + nums[1] + ... nums[i]
// We don't need an actual array, but rather a map to keep track of the sums, how many times they occured, and the current sums[i]
// Since the solution asks for CONTINGUOUS subarrays (arrays that maintain the same sequence as the original), this method works
// We can iterate through nums, calculating the running cumulative sum, and if sum - k exists as a previous prefix_sum, we add the freq of that sum to our solution
