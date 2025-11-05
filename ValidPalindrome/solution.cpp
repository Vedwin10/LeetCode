class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (char c : s) if (isalnum(c)) str += tolower(c);
        for (int i = 0; i < str.size(); ++i) if (str[i] != str[str.size()-1-i]) return false;
        return true;
    }
};

// strip all alphanumeric characters and check for symmetry