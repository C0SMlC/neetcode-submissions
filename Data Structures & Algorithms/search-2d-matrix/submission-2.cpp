class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            const vector<int>& currentArray = matrix[mid];
            int l = 0, r = currentArray.size() - 1;
            if (target >= currentArray[0] && target <= currentArray[r]) {
                while (l <= r) {
                    int currentArrayMid = l + (r - l) / 2;

                    if (currentArray[currentArrayMid] == target)
                        return true;
                    else if (currentArray[currentArrayMid] > target)
                        r = currentArrayMid - 1;
                    else
                        l = currentArrayMid + 1;
                }

                return false;  
            } else if (target < currentArray[0]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }
};
