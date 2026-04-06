public class Solution {
    public List<List<int>> ThreeSum(int[] nums) {
        List<List<int>> result = new List<List<int>>();
        Array.Sort(nums);  // Sort first: [-4, -1, -1, 0, 1, 2]
        int n = nums.Length;
        
        for (int i = 0; i < n - 2; i++)
        {
            // Skip duplicates for first element
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            
            // Early termination: if smallest is positive, no solution
            if (nums[i] > 0) 
                break;
            
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];  // We need nums[left] + nums[right] = target
            
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                
                if (sum == target)
                {
                    result.Add(new List<int> { nums[i], nums[left], nums[right] });
                    
                    // Skip duplicates for second element
                    while (left < right && nums[left] == nums[left + 1]) 
                        left++;
                    // Skip duplicates for third element
                    while (left < right && nums[right] == nums[right - 1]) 
                        right--;
                    
                    // Move both pointers after finding a valid triplet
                    left++;
                    right--;
                }
                else if (sum < target)
                {
                    left++;  // Need larger sum
                }
                else
                {
                    right--;  // Need smaller sum
                }
            }
        }
        
        return result;
    }
}