class Solution {
public:
    int hoursNeededWithCurrentK(vector<int>& piles, int k) {
        int hoursNeeded = 0;

        for (int pile : piles) {
            hoursNeeded += (pile + k - 1) / k;  
        }

        return hoursNeeded;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (hoursNeededWithCurrentK(piles, mid) <= h) {
                ans = mid;
                right = mid - 1;   
            } else {
                left = mid + 1;    
            }
        }

        return ans;
    }
};