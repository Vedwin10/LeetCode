class Solution {
public:
    bool isValid(string s) {
        stack<char> s_;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') s_.push(s[i]);
            else {
                if (s_.empty()) return false;

                char c = s_.top();
                s_.pop();

                if (s[i] == ')' && c != '(' ||
                s[i] == '}' && c != '{' ||
                s[i] == ']' && c != '[') return false;
            }
        }

        return s_.empty();
    }
};

// Use a stack to keep track of current open parenthesis, if a close parenthesis appears that doesn't match, false
// If stack isn't empty after, false
// If stack empty on a close parenthesis, false