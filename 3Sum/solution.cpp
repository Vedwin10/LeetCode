class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] < -nums[i]) ++j;
                else if (nums[j] + nums[k] > -nums[i]) --k;
                else {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    while (nums[j] == nums[j-1] && j < k) ++j;
                }
            }
        }
        return ret;
    }
};

// iterate through a sorted nums with i, and then use -nums[i] = nums[j] + nums[k] as an equation with j and k as left and right pointers
// in a while loop that runs while j < k. Check nums[i] == nums[i-1] and nums[j] == nums[j-1] to skip over duplicate numbers in the array