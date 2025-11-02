class Solution {
public:
    int calc(int x, int y, int op) {
        if (op == 1) return x + y;
        else if (op == 2) return x - y;
        else if (op == 3) return x * y;
        else return x / y;
    }

    int calculate(string s) {
        stack<pair<int, int>> s_;
        int sum = 0;
        int op = 1;     // 1 = +, 2 = -, 3 = *, 4 = /
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                --i;
                sum = calc(sum, num, op);
            } else if (s[i] == '+' || s[i] == '-') {
                if (!s_.empty()) {
                    sum = calc(s_.top().first, sum, s_.top().second);
                    s_.pop();
                }
                s[i] == '+' ? s_.push({sum, 1}) : s_.push({sum, 2});
                sum = 0;
                op = 1;
            } else if (s[i] == '*') {
                op = 3;
            } else if (s[i] == '/') {
                op = 4;
            }
        }

        if (!s_.empty()) {
            sum = calc(s_.top().first, sum, s_.top().second);
            s_.pop();
        }
        return sum;
    }
};

// Use the basic calculator algorithm, except instead of checking for '(' or ')', we push to the stack every time we see a '+' or '-'.
// To keep the stack from growing too large, we also add anything already in the stack to the current sum if we encounter a '+' or '-'
// We store operations with a variable, and perform that operation otherwise (ex: store * with op = 3, and the next number will modify sum with *)