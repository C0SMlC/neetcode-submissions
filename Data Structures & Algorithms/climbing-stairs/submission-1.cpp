class Solution {
public:
    unordered_map<int, int> seen;

    int climbStairs(int n) {
        if (n == 1 || n == 2)
            return n;

        if (seen.count(n))
            return seen[n];

        seen[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return seen[n];
    }
};