class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int p = 0;
        long long int num = 0;
        // check for leading whitespace
        while (p < s.size() && s[p] == ' ') ++p;
        // check for sign
        if (p < s.size() && s[p] == '-') {
            sign = -1;
            ++p;
        } else if (s[p] == '+') ++p;
        // check for leading zeros
        while (p < s.size() && s[p] == '0') ++p;
        // check for invalid characters and read in the number
        while (p < s.size()) {
            if (!isdigit(s[p])) break;
            num = (num * 10 + (s[p] - '0'));
            ++p;
            
            // round
            if (num > INT_MAX && sign == 1) return INT_MAX;
            else if (num > (long long)(INT_MAX) + 1 && sign == -1) return INT_MIN;
        }
        return (int)(num * sign);
    }
};

// The solution is pretty self explanatory, we can simply follow the algorithm they tell us to implement in the directions
// Inside the main while loop, we must check for nums greater than 2^31 - 1 or less than -2^31 
// because of inputs that might cause num to exceed its capacity LONG_MAX, the max size of a 64 bit signed integer
