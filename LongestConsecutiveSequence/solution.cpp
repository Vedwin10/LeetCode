class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int max = 0;
        for (const int num : s) {
            if (s.find(num - 1) == s.end()) {
                int counter = 1;
                while (s.find(num+counter) != s.end()) {
                    ++counter;
                }
                if (counter > max) max = counter;
            }
        }

        return max;
    }
};

// populate hashset and identify streak starter numbers as numbers where num - 1 doesn't exist, check using hashset to avoid checking
// duplicates in original array, like 2 in [1, 400, 200, 2, 2, 2, 3, 4]