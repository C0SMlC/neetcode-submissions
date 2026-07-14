class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charToIndexMap;
        int maxLen = 0;
        int startIndex = 0;

        for(int i=0; i < s.size(); i++){
            if(charToIndexMap.find(s[i]) != charToIndexMap.end() and startIndex <= charToIndexMap[s[i]]){
                startIndex = charToIndexMap[s[i]] + 1; 
            }
            charToIndexMap[s[i]] = i;
            maxLen = max(maxLen, i - startIndex + 1);
        }

        return maxLen;
    }
};
