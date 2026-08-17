class KthLargest {
private: 
    int k;
    vector<int>& nums;
    int distinctElements = 0;

public:
    KthLargest(int k, vector<int>& nums): k(k), nums(nums) {
    }
    
    int add(int val) {
        nums.push_back(val);

        sort(nums.begin(), nums.end());

        return nums[nums.size()  - k];
    }
};
