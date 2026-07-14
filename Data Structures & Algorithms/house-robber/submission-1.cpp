class Solution {
    unordered_map<int, int> iThAndMaxMonie;
public:
    int robbinHouses(vector<int>& nums, int i){
        if(i >= nums.size()) return 0;

        if(iThAndMaxMonie.find(i) != iThAndMaxMonie.end()) return iThAndMaxMonie[i];

        //skip current take next;
        int nextMonie = robbinHouses(nums, i+1);
        int currentMonie = nums[i] + robbinHouses(nums,i+2);

        iThAndMaxMonie[i] = max(nextMonie, currentMonie);

        return iThAndMaxMonie[i];
    }
    int rob(vector<int>& nums) {
        return robbinHouses(nums, 0);
    }
};
