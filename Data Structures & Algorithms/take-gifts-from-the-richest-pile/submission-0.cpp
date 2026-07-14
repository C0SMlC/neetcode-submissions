class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        for(int i = 0; i<k; i++){
            auto it = max_element(gifts.begin(), gifts.end());
            *it = (int)sqrt(*it);
        }

        long long sum = 0;

        for(auto gift: gifts){
            sum += gift;
        }

        return sum;
    }
};