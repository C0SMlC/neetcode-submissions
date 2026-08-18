class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        while (maxHeap.size() > 1) {
            int greatest = maxHeap.top();
            maxHeap.pop();

            int secondGreatest = maxHeap.top();
            maxHeap.pop();

            if (greatest != secondGreatest) {
                maxHeap.push(greatest - secondGreatest);
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};