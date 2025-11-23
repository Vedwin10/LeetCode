class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const string str : strs) {
            vector<int> alphabet(26, 0);
            for (const char c : str) {
                int idx = c - 'a';
                alphabet[idx]++;
            }
            string key = "";
            for (int i = 0; i < 26; ++i) {
                key += to_string(alphabet[i]) + ",";
            }
            mp[key].push_back(str);
        }

        vector<vector<string>> ret;
        for (const auto& p : mp) {
            ret.push_back(p.second);
        }

        return ret;
    }
};

// use a hashmap with a alphabetical-count key for a vector of strings to group anagrams
