class Solution {
public:
    void dfs(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& ans){
        if(start >= nums.size()) return;

        current.push_back(nums[start]);
        ans.push_back(current);
        dfs(nums, start + 1, current, ans);
        current.pop_back();

        dfs(nums, start + 1, current, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        vector<int> current;
        dfs(nums, 0, current, ans);
        return ans;
    }
};
