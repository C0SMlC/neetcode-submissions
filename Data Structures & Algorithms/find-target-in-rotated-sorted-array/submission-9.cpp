class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int firstNum = nums[0];
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;

            bool midInUpper = nums[mid] >= firstNum;
            bool targetInUpper = target >= firstNum;

            if (midInUpper == targetInUpper) {
                if (target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (targetInUpper)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};