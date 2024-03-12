class LFUCache {
public:
    int size;
    int currentSize;
    unordered_map<int,list<vector<int>>::iterator> nodeAddress;
    map<int,list<vector<int>>> freqMap;
    LFUCache(int capacity) {
        currentSize=0;
        size=capacity;
    }
    
    int get(int key) {
        int val=-1;
        if(nodeAddress.find(key)!=nodeAddress.end()){
            val=(*nodeAddress[key])[1];
            int freq=(*nodeAddress[key])[2];
            freqMap[freq].erase(nodeAddress[key]);
            if(freqMap[freq].empty())
                freqMap.erase(freq);
            freqMap[freq+1].push_front({key,val,freq+1});
            nodeAddress[key]=freqMap[freq+1].begin();
        }
        return val;
    }
    
    void put(int key, int value) {
        if(nodeAddress.find(key)==nodeAddress.end()){
            if(size==currentSize){
                int keyToDelete=freqMap.begin()->second.back()[0];
                freqMap.begin()->second.pop_back();
                if(freqMap.begin()->second.empty())
                    freqMap.erase(freqMap.begin());
                nodeAddress.erase(keyToDelete);
                currentSize--;
            }
            freqMap[1].push_front({key,value,1});
            nodeAddress[key]=freqMap[1].begin();
            currentSize++;
        } else {
            int freq=(*nodeAddress[key])[2];
            freqMap[freq].erase(nodeAddress[key]);
            if(freqMap[freq].empty())
                freqMap.erase(freq);
            freqMap[freq+1].push_front({key,value,freq+1});
            nodeAddress[key]=freqMap[freq+1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */