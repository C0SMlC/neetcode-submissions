class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> charset(26, -1);

        int maxSize = -1; 

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';  
            if (charset[idx] != -1) {
                maxSize = max(maxSize, i - charset[idx] - 1);  
            } else
                charset[idx] = i;
        }

        return maxSize;
    }
};