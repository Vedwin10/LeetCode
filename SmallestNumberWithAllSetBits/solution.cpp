class Solution {
public:
    int smallestNumber(int n) {
        int x = 1;
        while (x < n) {
            x = (x << 1) | 1;
        }
        return x;
    }
};

// Continuously add a 1 to binary numbers until you find the one greater than or equal to n
// e.g.: 1, 11, 111, ...
