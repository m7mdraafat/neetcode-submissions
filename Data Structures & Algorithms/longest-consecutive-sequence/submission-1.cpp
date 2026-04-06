class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // input: array of integers
        // output: length of the longest consective sequence of elements that can be formed.
        int res = 0;
        unordered_set<int> seen(nums.begin(), nums.end());

        for (int num : nums)
        {
            if (!seen.contains(num - 1))
            {
                int length = 1;
                int current = num + 1;
                while (seen.contains(current))
                {
                    length++;
                    current++;
                }

                res = max(res, length);
            }
        }

        return res; 
    }
};
