struct DLL {
    int key;
    int val;
    DLL* next;
    DLL* prev;

    DLL(int key, int val, DLL* prev, DLL* next) : key(key), val(val), prev(prev), next(next) {}
};

class LRUCache {
   private:
    unordered_map<int, DLL*> keyToNodeMap;
    DLL* head;
    DLL* tail;
    int capacity;

    void insertFront(DLL* node) {
        DLL* A = head->next;
        node->prev = head;
        node->next = A;
        head->next = node;
        A->prev = node;
    }

    void removeNode(DLL* node) {
        DLL* P = node->prev;
        DLL* N = node->next;
        P->next = N;
        N->prev = P;
    }

   public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new DLL(-1, -1, nullptr, nullptr);
        tail = new DLL(-1, -1, nullptr, nullptr);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (keyToNodeMap.find(key) == keyToNodeMap.end()) return -1;

        DLL* node = keyToNodeMap[key];
        removeNode(node);
        insertFront(node);
        return node->val;
    }

    void put(int key, int value) {
        if (keyToNodeMap.find(key) != keyToNodeMap.end()) {
            DLL* node = keyToNodeMap[key];
            node->val = value;
            removeNode(node);
            insertFront(node);
            return;
        }

        if ((int)keyToNodeMap.size() >= capacity) {
            DLL* lru = tail->prev;
            removeNode(lru);
            keyToNodeMap.erase(lru->key);
            delete lru;
        }

        DLL* newNode = new DLL(key, value, nullptr, nullptr);
        insertFront(newNode);
        keyToNodeMap[key] = newNode;
    }
};