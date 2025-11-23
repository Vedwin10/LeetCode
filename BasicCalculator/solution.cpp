class Solution {
public:
    int calculate(string s) {
        stack<pair<int, int>> s_;
        int sum = 0;
        int sign = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                --i;
                sum += num * sign;
            } else if (s[i] == '(') {
                s_.push({sum, sign});
                sum = 0;
                sign = 1;
            } else if (s[i] == ')') {
                sum = s_.top().first + (s_.top().second * sum);
                s_.pop();
            }
            else if (s[i] == '+') sign = 1;
            else if (s[i] == '-') sign = -1;
        }
        return sum;
    }
};

// We parse the string s and do the following:
// If it is a number, we make sure to parse all digits and add that number to sum with the corresponding sign. This handles cases like (1 + 2)
// If we see an open parenthesis, we reset sum to 0, and store the previous sum and the next operation in the stack. We also reset sign to 1 so that adding when sum = 0 works
// If we see a closed parenthesis, we add the top of the stack to the current sum with the correct operation
// Change the sign accordingly
