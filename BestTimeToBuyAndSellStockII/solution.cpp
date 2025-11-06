class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, buy_price = 0;
        bool holding = false;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (!holding && prices[i + 1] > prices[i]) {
                holding = true;
                buy_price = prices[i];
            } else if (holding && prices[i + 1] < prices[i]) {
                holding = false;
                res += prices[i] - buy_price;
            }
        }
        if (holding) res += prices[prices.size() - 1] - buy_price;
        return res;
    }
};

// Basically, if the stock rises, you buy, and if it's about to drop, sell
// The key idea here is that you buy/sell immediately if the stock rises/drops
// Why this works? Because if you graph the price of a stock, you can see that the MAXIMUM profit you can get over time is if 
// you hold the stock every single time it rises, which is what this algorithm is doing
