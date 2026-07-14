class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> charset;

        for(auto c:s){
            charset[c]++;
        }

        int maxLen = 0;

for(auto [c, len] : charset){
    if(len % 2 == 0) maxLen += len;     
    else             maxLen += len - 1; 
}

for(auto [c, len] : charset){
    if(len % 2 == 1){ maxLen += 1; break; } 
}

        return maxLen;
    }
};