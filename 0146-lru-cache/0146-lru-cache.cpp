class NodeList {
public:
    int key;
    int val;
    NodeList* prev;
    NodeList* next;
    
    NodeList(int k, int value) : key(k), val(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int totalCapacity;
    unordered_map<int, NodeList*> mp;
    NodeList* first;
    NodeList* last;
    
    LRUCache(int capacity) : totalCapacity(capacity), first(nullptr), last(nullptr) {}
    
    void updateList(int key) {
        NodeList* node = mp[key];
        
        if (node == last) {
            return;
        }
        
        if (node == first) {
            first = first->next;
        } else {
            node->prev->next = node->next;
        }
        
        if (node->next) {
            node->next->prev = node->prev;
        }
        
        node->prev = last;
        
        if (last) {
            last->next = node;
        }
        
        last = node;
        
        if (!first) {
            first = last;
        }
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            updateList(key);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->val = value;
            updateList(key);
            return;
        }
        
        NodeList* newNode = new NodeList(key, value);
        mp[key] = newNode;
        
        if (!first) {
            first = newNode;
        }
        
        if (last) {
            last->next = newNode;
        }
        
        newNode->prev = last;
        last = newNode;
        
        if (mp.size() > totalCapacity) {
            NodeList* toDelete = first;
            first = first->next;           
            mp.erase(toDelete->key);
            delete toDelete;
        }
    }
};
