class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() -1;
        vector<int> ans;
        
        while(left <= right){
            int maxInRange = -10001;
            for(int i=left; i<left+k and left+k<=right+1; i++){
                maxInRange = max(maxInRange, nums[i]);
            }
            if(maxInRange != -10001){
                cout << left<<endl;
                 ans.push_back(maxInRange);
            }

            left++;
        }

        return ans;
    }
};
