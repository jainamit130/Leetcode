class SummaryRanges {
public:
    map<int,int> mp;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        auto nextPtr = mp.lower_bound(value);
        bool nextMergePossible = true;
        bool prevMergePossible = true;
        auto prevPtr = nextPtr;
        if(nextPtr == mp.begin()){
            prevMergePossible=false;
        }
        if(nextPtr == mp.end()){
            nextMergePossible=false;
        }
        // 4 Cases 
        // Case 1: Merged to prev
        bool prevMerged = false;
        if(prevMergePossible){
            --prevPtr;
            if(prevPtr->second+1>=value){
                prevMerged = true;
                prevPtr->second = max(prevPtr->second+1,value);
            }
        }

        // Case 2: Merged to next
        bool nextMerged = false;
        if(nextMergePossible && nextPtr->first<=value+1){
            nextMerged=true;
            mp[min(nextPtr->first-1,value)]=nextPtr->second;
            mp.erase(nextPtr->first);
        }

        // Case 2: Both merge possible?
        if(nextMerged && prevMerged){
            mp[prevPtr->first]=mp[value];
            mp.erase(value);
        }

        // Case 4: Merged to neither
        if(!nextMerged && !prevMerged){
            mp[value]=value;
        }
        return;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        for(auto interval : mp)
            intervals.push_back({interval.first, interval.second});
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */