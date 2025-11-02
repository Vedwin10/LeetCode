class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int temp = nums[i] + nums[j] + nums[k];
                if (abs(target - temp) < diff) {
                    diff = abs(target - temp);
                    sum = temp;
                }
                if (temp <= target) ++j;
                else --k;
            }
        }
        return sum;
    }
};

// Run the 3Sum algorithm of an outer for loop and an inner 2 pointers loop, but no need to check for duplicates
// Compute the distance from target, and if it beats the best store that as the new best
