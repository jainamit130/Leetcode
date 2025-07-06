class NumberContainers {
public:
    unordered_map<int,int> indexToVal;
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>> valPqMap;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        valPqMap[number].push(index);
        indexToVal[index]=number;
    }
    
    int find(int number) {
        if(valPqMap.find(number)==valPqMap.end()) return -1;
        while(!valPqMap[number].empty()) {
            int indexInPq = valPqMap[number].top();
            int currNumInIndex = indexToVal[indexInPq];
            if(number!=currNumInIndex) {
                valPqMap[number].pop();
            } else {
                return indexInPq;
            }
        }
        valPqMap.erase(number);
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);



changes
85 -> 14
75 -> 40
27 -> 14

map
14 -> 22,27,85
40 -> 22,75

 */