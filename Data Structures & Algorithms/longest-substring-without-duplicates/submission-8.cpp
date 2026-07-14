class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int maxlen = 0;
        int left = 0;

        for(int i = 0; i < s.size(); i++){
            if(charMap.find(s[i]) != charMap.end())
                left = max(left, charMap[s[i]] + 1); 
                maxlen = max(maxlen, i - left + 1);   
                
            charMap[s[i]] = i;
               
        }

        return maxlen;
    }
};