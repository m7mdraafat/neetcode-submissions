public class Solution {
    public int MaxProfit(int[] prices) {
        int max = 0;
        int min = int.MaxValue;
        for (int i = 1; i < prices.Length; i++)
        {
            min = Math.Min(min, prices[i - 1]);
            max = Math.Max(prices[i] - min, max);
        }

        return max;
    }
}
