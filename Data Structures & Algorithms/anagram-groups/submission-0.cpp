class Solution {
   public:
    string getKey(string s) {
        vector<int> chars(26, 0);
        for (auto ch : s) {
            chars[ch - 'a']++;
        }

        string key;
        for (auto ch : chars) {
            key += '#' + ch;
        }

        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        for (string str : strs) {
            string key = getKey(str);
            anagramMap[key].push_back(str);
        }

        vector<vector<string>> result;
        for (auto& pair : anagramMap) {
            result.push_back(pair.second);
        }

        return result;
    }
};
