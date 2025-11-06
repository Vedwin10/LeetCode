class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s1.size();
        unordered_map<char, int> s1_mp;
        for (int i = 0; i < len; ++i) s1_mp[s1[i]]++;
        int have = 0, need = s1_mp.size();
        int l = 0, r = 0;

        unordered_map<char, int> s2_mp;
        while (r < s2.size()) {
            char c = s2[r];
            if (s1_mp.count(c)) s2_mp[c]++;
            if (s1_mp == s2_mp && (r - l) + 1 == len) return true;
            else if ((r - l) + 1 == len) {
                char lc = s2[l];
                if (s1_mp.count(lc)) s2_mp[lc]--;
                ++l;
            }
            ++r;
        }

        return false;
    }
};

// Using the algorithm from MinimumWindowSubstring, except with a few key differences:
// We only check if s1_mp == s2_mp, we can't have a have and need variable because it has to match exactly
// If the condition is true, we immediately return true
// The condition to shrink the window is if the window == len, since it can't exceed len ever
