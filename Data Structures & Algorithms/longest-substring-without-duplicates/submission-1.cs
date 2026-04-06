public class Solution {
    public int LengthOfLongestSubstring(string s) {
        HashSet<char> st = new HashSet<char>();
        int res = 0;
        int l = 0;
        for(int r = 0;  r < s.Length; r++)
        {
            while (st.Contains(s[r]))
            {
                st.Remove(s[l]);
                l++;
            }
            st.Add(s[r]);
            res = Math.Max(res, r - l + 1);
        }

        return res;
    }
}
