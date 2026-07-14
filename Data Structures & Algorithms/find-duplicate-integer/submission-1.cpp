class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (fast != slow) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        cout << slow;

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};