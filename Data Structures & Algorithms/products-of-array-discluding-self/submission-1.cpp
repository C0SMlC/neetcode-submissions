class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProd(n, 1);

        for(int i=1; i<n; i++){
            prefixProd[i] = prefixProd[i-1] * nums[i-1];
        }

        for(int i=0; i<n; i++){
            cout << prefixProd[i]<< " ";
        }
        cout <<endl;
        int suffixProd = 1;
        for(int i=n-1; i>=0; i--){
        cout << suffixProd <<" ";
           prefixProd[i] = prefixProd[i] * suffixProd;
           suffixProd = nums[i]* suffixProd;
        }   
        return prefixProd;
    }
};
