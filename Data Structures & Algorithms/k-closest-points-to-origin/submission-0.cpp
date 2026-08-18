class comparePair {
   public:
    bool operator()(pair<int, vector<int>> a, pair<int, vector<int>> b) {
        return a.first < b.first;
    }
};

class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, comparePair> maxHeap;

        for (int i = 0; i < points.size(); i++) {
            int distance = pow(points[i][0], 2) + pow(points[i][1], 2);
            maxHeap.push(make_pair(distance, points[i]));
            if (maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> result;

        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};
