class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> stk;
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                stk.push({res, num});
                --i;
            } else if (s[i] == '[') {
                res = "";
            } else if (s[i] == ']') {
                pair<string, int> tp = stk.top(); stk.pop();
                string tmp = "";
                for (int j = 0; j < tp.second; ++j) tmp += res;
                res = tp.first + tmp;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};

// The algorithm works as follows:
// Iterate over the string s character by character
// If we come across a number, push our current state and that number to the stack
// Once we come across the '[', we reset our state to a blank string to read in what's about to follow
// Once we come across a ']', our most recent '[' has ended, so we pop the top of the stack, state = stack.state + (state * stack.int)
// If we read anything else, add it to the current state
