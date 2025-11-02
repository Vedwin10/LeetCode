class Solution {
public:
    int calc(int x, int y, string operation) {
        char op = operation[0];
        if (op == '+') return x + y;
        else if (op == '-') return x - y;
        else if (op == '*') return x * y;
        else return x / y;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s_;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int y = s_.top(); s_.pop();
                int x = s_.top(); s_.pop();
                int sum = calc(x, y, tokens[i]);
                s_.push(sum);
            } else {
                int num = stoi(tokens[i]);
                s_.push(num);
            }
        }
        return s_.top();
    }
};

// A stack is critical to evaluate RPN
// If the token is a number, we push to the stack
// If the token is an operation, we know that there are 2 numbers in the stack guaranteed, so we can pop them and execute the operation tokens[i] on them,
// then push that new number to the stack