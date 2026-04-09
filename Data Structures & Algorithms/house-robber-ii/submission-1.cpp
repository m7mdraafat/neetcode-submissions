class Solution {
    vector<vector<int>> memo;
public:
    int maxAmount(vector<int>& nums, bool invalid, int index) {
        if (index >= nums.size() || (invalid && index == nums.size() - 1))
            return 0;

        if (memo[index][invalid] != -1)
            return memo[index][invalid];
        
        int skip = maxAmount(nums, invalid, index + 1);
        int take = nums[index] + maxAmount(nums, invalid || index == 0, index + 2);

        return memo[index][invalid] = max(skip, take);
    } 
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        memo.resize(nums.size(), vector<int>(2, -1));
        return max(maxAmount(nums, true, 0), maxAmount(nums, false, 1));
    }
};
