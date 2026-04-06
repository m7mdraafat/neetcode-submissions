class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // input: array
        // input range: 10^3: O(n^2) acceptable, but needed O(n) -> map
        // Find a pair -> two pointers or hash map
        // Return indices: Hash map
        /* Algorithm
         - define unordered_map
         - iterate over the elements
         - calculate the component
         - if component exists return minimum (current index, component index)
        */
        unordered_map<int, int> mp;
        int firstIdx = -1, lastIdx = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            int component = target - nums[i];
            if (mp.find(component) != mp.end())
            {
                firstIdx = min(mp[component], i);
                lastIdx = max(mp[component], i);
                break;
            }

            mp[nums[i]] = i; 
        }

        return { firstIdx, lastIdx };
    }
};
