class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // input: array of strings
        // phrase: return longest common prefix of all strings.
        // if no -> ""
        // input size: 10^2 -> n^2 valid
        // str length: 10^2 -> all same length? no
        
        string prefix = strs[0]; // bat
        for (int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            while (j < min(prefix.length(), strs[i].length()))
            {
                if (prefix[j] != strs[i][j])
                {
                    break;
                }

                j++;
            }

            prefix = prefix.substr(0, j);
        }

        return prefix;
    }
};