class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_map;
        for (char c : t) t_map[c]++;

        int l = 0, r = 0;
        unordered_map<char, int> s_map;
        int min = INT_MAX, start = 0;
        int have = 0, need = t_map.size();

        while (r < s.size()) {
            char c = s[r];
            if (t_map.count(c)) {
                s_map[c]++;
                if (s_map[c] == t_map[c]) ++have;
            }

            while (have == need) {
                if ((r - l) + 1 < min) {
                    min = (r - l) + 1;
                    start = l;
                }

                char lc = s[l];
                if (t_map.count(lc)) {
                    s_map[lc]--;
                    if (s_map[lc] < t_map[lc]) --have;
                }
                ++l;
            }
            ++r;
        }
        return min == INT_MAX ? "" : s.substr(start, min);
    }
};

// The way that this algorithm works is that you have 2 pointers, starting at 0 (for strings length 1)
// until r reaches the end, we run the following:
// if the current window matches t (which we track with have and need), we shrink from l until the window no longer matches, updating the min length and start index each time
// if l is a character in t, we decrease that char in s_map, and if it's freq drops below t, we now need 1 more var so we do --have
// increment r, and finally return "" if min was never updated (no window found) otherwise return the substring of length min starting from index start
