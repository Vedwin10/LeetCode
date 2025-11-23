class Solution {
public:

    string encode(vector<string>& strs) {
        string ret = "";
        for (const string& str : strs) {
            ret += to_string(str.size()) + "#" + str;
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        int i = 0;
        while (i < s.size()) {
            string numstr = "";
            while (s[i] != '#') {
                numstr += s[i];
                ++i;
            }
            int num = stoi(numstr);
            ++i;
            string curr = s.substr(i, num);
            i += num;
            ret.push_back(curr);
        }
        return ret;
    }
};

// use a separator with the length of the string before it, then the string itself
