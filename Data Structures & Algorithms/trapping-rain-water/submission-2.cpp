class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();

        int left = 0, right = n - 1, leftMax = 0, rightMax = 0, trappedWater = 0;

        while(left <= right){
            if(leftMax < rightMax){
                leftMax = max(leftMax, height[left]);
                trappedWater += max(leftMax - height[left], 0);
                left++;
            }
            else {
                rightMax = max(rightMax, height[right]);
                trappedWater += max(rightMax - height[right], 0);
                right--;
            }
        } 
        
        return trappedWater; 
    }
};