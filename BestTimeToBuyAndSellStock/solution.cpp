class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int res = 0;
        for (int price : prices) {
            if (price < min) min = price;
            if (price - min > res) res = price - min;
        }
        return res;
    }
};

// The algorithm is pretty simple. Iterate through prices, storing the current buy price (or minimum that you've seen), and profit is just 
// the current price - buy price. Update profit if it exceeds the previous max. Initialize profit to 0 for cases where no profit can be made
