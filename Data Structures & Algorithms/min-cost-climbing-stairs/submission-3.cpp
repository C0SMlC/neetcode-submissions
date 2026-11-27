class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() -1;
        
        int next1 = 0;
        int next2 = 0;

        while(n >= 0){
            int curr = cost[n] + min(next1, next2);

            next2 = next1;
            next1 = curr;

            n--;
        }

        return min(next1, next2);
    }
};
