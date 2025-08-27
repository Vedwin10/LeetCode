class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<vector<int>> vect(nums.size()+1);

        for (const int num : nums) {
            mp[num]++;
        }
        for (const auto& [key, value] : mp) {
            vect[value].push_back(key);
        }

        vector<int> ret;
        for (int i = vect.size() - 1; i >= 0; --i) {
            for (const int num : vect[i]) {
                ret.push_back(num);
                if (ret.size() == k) return ret;
            }
        }
        return ret;
    }
};

// use bucket sort with indices as freqency, nested for loop to generate return vector