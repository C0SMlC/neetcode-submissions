class Solution {
   public:
    int trap(vector<int>& height) {
        int size = height.size();

        vector<int> maxFromLeft(size, height[0]);
        vector<int> maxFromRight(size, height[size - 1]);

        for (int i = 1; i < size; i++) {
            maxFromLeft[i] = max(maxFromLeft[i - 1], height[i]);
        }

        for (int i = size - 2; i >= 0; i--) {
            maxFromRight[i] = max(maxFromRight[i + 1], height[i]);
        }

        int ans = 0;

        for (int i = 0; i < size; i++) {
            int mini = min(maxFromLeft[i], maxFromRight[i]);
            ans += max(mini - height[i], 0);

            // cout << maxFromLeft[i]<< " " << maxFromRight[i] << " " << height[i]<< " " <<ans<<endl;
        }

        return ans;
    }
};
