class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int, int> carToSpeed;

        for (int i = 0; i < position.size() and i < speed.size(); i++) {
            carToSpeed[position[i]] = speed[i];
        }

        sort(position.begin(), position.end(), greater<int>());

        int numOfFleet = 1;
        double lastCarsTime = (double)(target - position[0]) / carToSpeed[position[0]];

        for (int i = 1; i < position.size(); i++) {
            if ((double)(target - position[i]) / carToSpeed[position[i]] > lastCarsTime) {
                numOfFleet++;
                lastCarsTime = (double)(target - position[i]) / carToSpeed[position[i]];
            }
        }

        return numOfFleet;
    }
};
