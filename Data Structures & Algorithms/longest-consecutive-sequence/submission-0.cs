public class Solution {
    public int LongestConsecutive(int[] nums) {
        HashSet<int> st = new HashSet<int>(nums);

        int max = 0;
        foreach (int num in st){
            if (!st.Contains(num - 1)) {
                int length = 1;
                int current = num + 1;
                while (st.Contains(current)) {
                    length++;
                    current++;
                }

                max = Math.Max(max, length);
            }
        }

        return max;
    }
}
