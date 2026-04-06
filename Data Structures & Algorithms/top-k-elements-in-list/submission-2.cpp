class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // input: array, k -> distinct elements in num
        // input range: 10^4
        // questions
        // 1. is array sorted by default? -> no.
        
        // algorithm: sorting problem
        // 1. count occurences of each element in the given array.
        // 2. define max heap based on the occurences [occurences, value]
        // 3. get the top k elements from the heap will be sorted by occurences

        unordered_map<int, int> count;
        for (int num : nums)
        {
            if (!count.contains(num)) {
                count[num] = 0;
            }

            count[num]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto &[key, value] : count)
        {
            pq.push({value, key});
        }

        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
