class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maxAreaSpan = INT_MIN;

        while(l < r){
            int minAreaSpan = min(heights[l], heights[r]) * (r - l);

            if(heights[l] < heights[r]) l++;
            else r--;

            maxAreaSpan = max(maxAreaSpan, minAreaSpan);
        }

        return maxAreaSpan;
    }
};
