class Solution {
public:
    int maxArea(vector<int>& heights) {
        // input: array heights where heights[i] represents the height of the ith bar.
        // output: choose any two bars to form a container to maximize the (container) rectangle size.

        // there two nested loops -> the question is how can we cut or reduce the inner for loop?
        
        int mx = 0;
        int left = 0, right = heights.size() - 1;
        while (left < right)
        {
            int mn = min(heights[left], heights[right]);
            int area = mn * (right - left);
            mx = max(mx, area);

            if (heights[left] > heights[right]) {
                right--;
            }
            else {
                left++; 
            }                
        }


        return mx;
    }
};
