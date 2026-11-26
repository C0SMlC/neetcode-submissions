class Solution {
   public:
    vector<vector<int>> ans;

    void findCombinationSum(vector<int>& nums, vector<int>& currentArray, int target, int sum, int i) {
        if (sum > target) return;

        if (sum == target) {
            ans.push_back(currentArray);
            return;
        }

        while (i < nums.size()) {
            currentArray.push_back(nums[i]);
            findCombinationSum(nums, currentArray, target, sum + nums[i], i);
            currentArray.pop_back();
            i++;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int size = nums.size() - 1;
        vector<int> curr;
        findCombinationSum(nums, curr, target, 0, 0);
        return ans;
    }
};
