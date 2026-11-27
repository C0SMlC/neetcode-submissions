class Solution {
public:
    vector<int> visited{vector<int>(100, -1)};

    int findMinCostClimibingStairs(vector<int>& cost, int i){
        if(i >= cost.size()) return 0;
        if(visited[i] != -1) return visited[i];
        int minCost = cost[i] + min(findMinCostClimibingStairs(cost, i+1), findMinCostClimibingStairs(cost, i+2));
        visited[i] = minCost;
        return minCost;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // we have two choice, take i or take i+1 at time t, cant take both.
        return min(findMinCostClimibingStairs(cost, 0), findMinCostClimibingStairs(cost, 1));
    }
};
