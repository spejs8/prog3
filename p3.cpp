class Solution {
    public:
        int maxArea(vector<int>& height) {
            int maxvoda = 0;
            int left = 0;
            int right = height.size() - 1;
             while (left < right) {
                int voda = min(height[left], height[right]) * (right - left);
                maxvoda = max(maxvoda, voda);
                if (height[left] < height[right]) {
                    left++;
                } else {
                    right--;
                }
            }
            return maxvoda;
        }
    };
    