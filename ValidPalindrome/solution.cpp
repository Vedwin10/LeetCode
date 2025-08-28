class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = "";
        for (int i = 0; i < s.size(); ++i) {
            if (isalnum(s[i])) cleaned += tolower(s[i]);
        }

        for (int i = 0; i < cleaned.size() / 2; ++i) {
            if (cleaned[i] != cleaned[cleaned.size()-1-i]) return false;
        }

        return true;
    }
};

// strip all alphanumeric characters and check for symmetry