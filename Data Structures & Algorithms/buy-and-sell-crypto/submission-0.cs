public class Solution {
    public int MaxProfit(int[] prices) {
        int max = 0;
        for (int i = 1; i < prices.Length; i++)
        {
            for (int j = 0; j < i; j++) {
                max = Math.Max(prices[i] - prices[j], max);
            }
        }

        return max;
    }
}
