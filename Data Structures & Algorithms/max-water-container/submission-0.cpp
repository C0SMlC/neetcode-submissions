class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() -1;

        int maxAreaSoFar = INT_MIN;

        while(i<j){
            maxAreaSoFar = max(maxAreaSoFar, (j-i)*min(heights[i], heights[j]));

            if(heights[i] > heights[j]) j--;
            else i++;


        }

        return maxAreaSoFar;
    }
};
