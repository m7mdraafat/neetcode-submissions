class Solution {
public:
    bool isAnagram(string s, string t) {
        // nlog n solution. 
        if(s.size()!=t.size())return false; 
        else if(s == t) return true;

        unordered_map<int, int>mps, mpt;
        for(char c : s){
            mps[c]++;
        }
        for(char c : t){
            mpt[c]++;
        }

        for(auto & p : mps){
            if(p.second != mpt[p.first])
                return false;
        }

        return true; 
        
    }
};
