class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_map<int, int> chars_to_recent_idx;

        int max_len = 0;

        for(int i=0; i <s.size(); i++){
            if(chars_to_recent_idx.find(s[i]) != chars_to_recent_idx.end() and chars_to_recent_idx[s[i]] >= left){
                max_len = max(max_len, (i - left));
                left = chars_to_recent_idx[s[i]] + 1;
            }else{
                max_len =  max(max_len, (i - left)+1);
            }

            chars_to_recent_idx[s[i]] = i;
        }

        return max_len;
    }
};
