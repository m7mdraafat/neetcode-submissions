class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0, n = prices.size();

        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++)
            {
                int profit = prices[j] - prices[i];
                mx = max(mx, profit);
            }
        }

        return mx;
    }
};
