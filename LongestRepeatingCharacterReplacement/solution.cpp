class Solution {
public:
    int characterReplacement(string s, int k) {
        int max = 0;
        int len = k;
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        while (r < s.size()) {
            char c = s[r];
            mp[c]++;
            if (mp[c] > max) {
                max = mp[c];
                len = k + max;
            }
            if ((r - l) + 1 > len) {
                char lc = s[l];
                mp[lc]--;
                ++l;
            }
            ++r;
        }
        return len > s.size() ? s.size() : len;
    }
};

// basically we return the length of the longest substring which can be found as k + x, where x is
// the # of occurences of the most occuring letter in that window
// the window cannot exceed k + x, when it does (window > len), shrink the window by 1
// we use a hashmap to keep track of count in the window, increment and decrement hashmap value as we grow/shrink window
// make sure we return a length that is <= s.size()
