class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> rightMostMax(n,  0);
        int currentMax =  height[n-1];
        for(int i = n-2; i>=0; i--){
            rightMostMax[i] = max(currentMax, height[i]);
            currentMax = max(currentMax, height[i]);
        }

        int leftMostMax = height[0];
        int trappedWater = 0;
        for(int i=1; i<n; i++){
            cout <<leftMostMax<<" "<< rightMostMax[i] << " "<<  height[i] <<" "<<(min(leftMostMax, rightMostMax[i])- height[i])<<" "<<endl;
            trappedWater += max((min(leftMostMax, rightMostMax[i])- height[i]), 0);
            leftMostMax = max(leftMostMax, height[i]);
        }

        return trappedWater;
    }
};
