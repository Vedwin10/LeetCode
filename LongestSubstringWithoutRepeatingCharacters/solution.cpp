class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int l = 0, r = l + 1;
        unordered_map<char, int> mp;
        mp[s[0]] = 0;
        int res = 1;
        while (r < s.size()) {
            if (mp.find(s[r]) != mp.end()) {
                int tmp = mp[s[r]];
                for (int i = l; i <= mp[s[r]]; ++i) mp.erase(s[i]);
                l = tmp + 1;
            }
            mp[s[r]] = r;
            if (r - l + 1 > res) res = (r - l) + 1;
            ++r;
        }
        return res;
    }
};

// Basically, I have 2 pointers, setting them equal to 0 and 0 + 1 for l and r respectively
// Handle edge cases of empty strings at the beginning
// Set res = 1, because the first char is length 1
// While r < size, we:
// Have a hashamp keeping track of all chars in our window
// If we come across a duplicate, set l to 1 past that duplicate, and remove all characters from hashmap up to that index
// Set the index of the character read in
// Update res if the window is longer
// Increment r
