class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        int minInNums = nums[l];

        while(l<=r){
            int mid = l + (r - l) /2;
            if(minInNums <= nums[mid]){
                l = mid + 1;
            }else{
                minInNums = nums[mid];
                r = mid - 1;
            }
        }

        return minInNums;
    }
};
