class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<nums.size(); i++){
            int cand1 = nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            //two sum
            int low = i+1;
            int end = nums.size() -1;

            while(end > low){
                int sum = cand1 + nums[low] + nums[end];

                if(sum > 0) end--;
                else if(sum < 0) low++;
                else{
                    ans.push_back({cand1, nums[low], nums[end]});
                    low++;
                    end--;

                    while (low < end && nums[low] == nums[low - 1]) {
                        low++;
                    }
                }
            }
        }

        return ans;
    }
};
