public class Solution {
    public int[] TwoSum(int[] numbers, int target) {
        int n = numbers.Length;
        
        for (int i = 0; i < n; i++)
        {
            // Search in range [i+1, n-1] to avoid using same element
            int foundIdx = BinarySearch(i + 1, n - 1, target - numbers[i], numbers);
            if (foundIdx != -1)
                return new int[] { i + 1, foundIdx + 1 };
        }

        return new int[] { -1, -1 };  // Not found
    }

    private int BinarySearch(int l, int r, int target, int[] nums)
    {
        while (l <= r)
        {
            int mid = l + (r - l) / 2;  
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid - 1;
            else 
                l = mid + 1;
        }
        return -1;
    }
}