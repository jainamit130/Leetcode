class List {
public:
    int val;
    List* prev;
    List* next;
    List(int value) {
        val = value;
        prev = NULL;
        next = NULL;
    }
};
vector<List*> deleteKey(List* head, List* node, List* mru, List* lru) {
    if (!node)
        return {head, mru, lru}; // Check if node is NULL.

    List* prevPtr = node->prev;
    List* nextPtr = node->next;

    // Update MRU and LRU pointers if needed.
    if (mru && mru->val == node->val) {
        mru = mru->next;
    }
    if (lru && lru->val == node->val) {
        lru = lru->prev;
    }

    // Remove node from the list.
    if (prevPtr) {
        prevPtr->next = nextPtr;
    } else {
        head = nextPtr; // Update head if node was the head.
    }

    if (nextPtr) {
        nextPtr->prev = prevPtr;
    }

    // If both nextPtr and prevPtr are NULL, it means the list is empty now.
    if (!nextPtr && !prevPtr) {
        return {NULL, NULL, NULL};
    }

    return {head, mru, lru};
}

pair<vector<List*>, List*> insertKey(List* node, List* mru, List* lru,
                                     int key) {
    List* newNode = new List(key);

    if (!lru) {
        lru = newNode; // If the list was empty, set newNode as LRU.
    }

    mru = newNode; // Always update MRU to the new node.

    newNode->next = node;
    if (node) {
        node->prev = newNode; // Update the previous pointer of the old head.
    }

    return {{newNode, mru, lru}, newNode};
}

class LFUCache {
public:
    unordered_map<int, List*> mpNode;
    unordered_map<int, pair<int, int>> mpCountVal;
    map<int, vector<List*>> mp;
    int currSize;
    int size;
    LFUCache(int capacity) {
        currSize = 0;
        size = capacity;
    }

    int get(int key) {
        if (mpCountVal.find(key) == mpCountVal.end()) {
            return -1; // Key not found.
        }

        int count = mpCountVal[key].first;
        int value = mpCountVal[key].second;

        // Remove the node from the current count's frequency list.
        vector<List*> newDeletedList =
            deleteKey(mp[count][0], mpNode[key], mp[count][1], mp[count][2]);

        // If this frequency list is now empty, erase it.
        if (newDeletedList[0] == NULL) {
            mp.erase(count);
        } else {
            mp[count] = newDeletedList;
        }

        // Increase the frequency count and move the node to the next frequency
        // list.
        if (mp.find(count + 1) != mp.end()) {
            auto [newList, newNode] = insertKey(
                mp[count + 1][0], mp[count + 1][1], mp[count + 1][2], key);
            mp[count + 1] = newList;
            mpNode[key] = newNode;
        } else {
            auto [newList, newNode] = insertKey(NULL, NULL, NULL, key);
            mp[count + 1] = newList;
            mpNode[key] = newNode;
        }

        // Update the frequency count in the count-value map.
        mpCountVal[key].first = count + 1;
        return value;
    }

    void put(int key, int value) {
        // If key is already present, update its value and move it to the new
        // frequency list.
        if (mpCountVal.find(key) != mpCountVal.end()) {
            get(key); // Move the key to the next frequency list.
            mpCountVal[key].second = value; // Update the value.
            return;
        }

        // If the cache is at capacity, evict the least frequently used key.
        if (currSize == size) {
            int firstCount = mp.begin()->first;
            int toDelete = mp[firstCount][2]->val;

            // Remove from mpCountVal and mpNode.
            mpCountVal.erase(toDelete);
            mpNode.erase(toDelete);

            // Delete the LRU node from the current least frequency list.
            vector<List*> newDeletedList =
                deleteKey(mp[firstCount][0], mp[firstCount][2],
                          mp[firstCount][1], mp[firstCount][2]);

            // If the frequency list becomes empty, erase it.
            if (newDeletedList[0] == NULL) {
                mp.erase(firstCount);
            } else {
                mp[firstCount] = newDeletedList;
            }
            currSize--;
        }

        // Insert the new key with frequency 1.
        if (mp.find(1) == mp.end()) {
            auto [newList, newNode] = insertKey(NULL, NULL, NULL, key);
            mp[1] = newList;
            mpNode[key] = newNode;
        } else {
            auto [newList, newNode] =
                insertKey(mp[1][0], mp[1][1], mp[1][2], key);
            mp[1] = newList;
            mpNode[key] = newNode;
        }

        // Add the key with count 1 and its value.
        mpCountVal[key] = {1, value};
        currSize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */