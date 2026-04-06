class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // input: array of nums
        // output: array where res[i] is the product of all the elements of nums except nums[i]
        // q:
        // 1. input length
        // 2. value range
        // multiply prefix, suffix
        // 1,  1,   2,  8, 48
        // 48  48   24  6   1
        // eq: for each index the result equals pref[i] * post[i]
        int n = nums.size();
        vector<int>pref(n), post(n);
        pref[0] = 1;
        post[n - 1] = 1;

        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            post[i] = post[i+1] * nums[i+1];
        }

        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back(pref[i] * post[i]);
        }

        return res;
    }
};
