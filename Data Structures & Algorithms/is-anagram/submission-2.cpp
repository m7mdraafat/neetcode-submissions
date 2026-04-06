class Solution {
public:
    bool isAnagram(string s, string t) {
        // Time: O(n)
        // Space: O(n)
        if (s.length() != t.length()) return false;

        unordered_map<char, int> s1, s2;
        for (char c : s)
        {
            s1[c]++;
        }

        for (char c : t)
        {
            s2[c]++;
        }

        for (auto &[ch, conut] : s1)
        {
            if (s2[ch] != conut)
            {
                return false;
            }
        }

        return true;
    }
};