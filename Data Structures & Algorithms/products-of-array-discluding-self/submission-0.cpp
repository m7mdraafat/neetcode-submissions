class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n+1), post(n+1);
        pref[0] = 1; 
        post[n] = 1; 

        for(int  i =0; i < n; i++){
            pref[i+1] = pref[i] * nums[i];
        }

        for(int i = n -1; i>=0; i--){
            post[i] = post[i+1] * nums[i];
        }

        vector<int> res; 
        for(int i =0; i < n; i++){
            res.push_back(pref[i] * post[i+1]);
        }

        return res; 
    }
};
