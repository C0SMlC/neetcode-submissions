class Solution {
public:
    vector<vector<int>> ans;

    void findCombinationSum(vector<int>& nums, vector<int> currentArray, int target, int sum, int i, int j){
        if(sum > target) return;

        if(sum == target){ ans.push_back(currentArray); return;}

        while(i <= j and i <= nums.size()){
            int internalSum = sum;
            internalSum += nums[i];
            vector<int> currArr = currentArray;

            currArr.push_back(nums[i]);

            findCombinationSum(nums, currArr, target, internalSum, i, j);

            i++;
        }

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int size = nums.size() -  1;

        // for(int i=0; i<= size; i++){
            findCombinationSum(nums, {}, target, 0, 0 , size);
        // }

        return ans;
    }
};
