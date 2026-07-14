class TrieNode {
   public:
    TrieNode* childNodes[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            childNodes[i] = nullptr;
        }
    }
};

class PrefixTree {
   public:
    TrieNode* root;

    PrefixTree() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (curr->childNodes[idx] == nullptr) curr->childNodes[idx] = new TrieNode();

            curr = curr->childNodes[idx];
        }

        curr->isEnd = true;
    }

    bool search(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (curr->childNodes[idx] == nullptr) return false;

            curr = curr->childNodes[idx];
        }

        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (char c : prefix) {
            int idx = c - 'a';

            if (curr->childNodes[idx] == nullptr) return false;

            curr = curr->childNodes[idx];
        }

        return true;
    }
};
