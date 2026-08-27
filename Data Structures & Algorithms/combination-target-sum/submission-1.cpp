class Solution {
    void dfs(const vector<int>& nums, int start, int remaining, vector<int>& current,
             vector<vector<int>>& result) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }

        if (remaining < 0) {
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            dfs(nums, i, remaining - nums[i], current, result);
            current.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;

        dfs(nums, 0, target, current, result);

        return result;
    }
};
