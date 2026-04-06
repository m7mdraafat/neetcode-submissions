class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(); 
        unordered_map<int, int>seen;
        vector<int>v;
        for(int i =0; i < n; i++){
            int complement = target - nums[i];
            if(seen.find(complement) != seen.end()){
                v.push_back(seen[complement]);
                v.push_back(i);
                break; 
            }

            seen[nums[i]] = i;
        }

        return v;
    }
};
