class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charFreq;
        int maxAppearedCharInWindow = 0;
        int left = 0;
        int right = 0;
        int n = s.size();
        int ans = 0;

        while(right < n){
            charFreq[s[right]]++;
            maxAppearedCharInWindow = max(maxAppearedCharInWindow, charFreq[s[right]]);

            int windowSize = right - left + 1;
            int replacementNeededInCurrentWindow = windowSize - maxAppearedCharInWindow;

            if(replacementNeededInCurrentWindow > k){
                charFreq[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }
        
        return ans;
    }
};
