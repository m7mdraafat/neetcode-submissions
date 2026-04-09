class Solution {
    vector<vector<int>> memo;
public:
    int maxAmount(vector<int>& nums, bool skip, int index) {
        if (index >= nums.size() || (skip && index == nums.size() - 1))
            return 0;

        if (memo[index][skip] != -1)
            return memo[index][skip];
        
        memo[index][skip] = max(maxAmount(nums, skip, index + 1),
                                nums[index] + maxAmount(nums, skip || index == 0, index + 2));

        return memo[index][skip];
    } 

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        memo.resize(nums.size(), vector<int>(2, -1));
        return max(maxAmount(nums, true, 0), maxAmount(nums, false, 1));
    }
};
