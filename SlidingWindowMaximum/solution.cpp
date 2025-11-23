class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = 0;
        vector<int> res;
        map<int, int> mp;
        for (; r < k - 1; ++r) mp[nums[r]]++;
        while (r < nums.size()) {
            mp[nums[r]]++;
            auto it = mp.end(); --it;
            res.push_back(it->first);
            mp[nums[l]]--;
            if (mp[nums[l]] == 0) mp.erase(nums[l]);
            ++l;
            ++r;
        }
        return res;
    }
};

// I have a sliding window with a ordered map to keep track of numbers and frequences.
// I use map.end()-- to access the maximum element in the current window
