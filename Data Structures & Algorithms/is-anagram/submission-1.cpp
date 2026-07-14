class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> characterMap;

        for(char c:s){
            characterMap[c] += 1;
        }

        for (char c : t) {
            characterMap[c]--;
            if (characterMap[c] < 0) {
                return false;
            }
        }

        return true;

    }
};