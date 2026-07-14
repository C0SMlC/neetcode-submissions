class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Bucket sort
        int n = nums.size();
        unordered_map<int, int> eleFreqMap;

        for (auto num : nums) {
            eleFreqMap[num]++;
        }

        vector<vector<int>> bucket(n + 1);
        for (auto [num, f] : eleFreqMap) {
            bucket[f].push_back(num);
        }

        vector<int> res;
        for (int i = n; i >= 0, k > 0; i--) {
            for (auto num : bucket[i]) {
                res.push_back(num);
                k--;
            }
        }

        return res;
    }
};
