class SummaryRanges {
public:
    vector<int> vals;
    unordered_set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        if(st.find(value)!=st.end()){
            return;
        }
        st.insert(value);
        vals.push_back(value);
        sort(vals.begin(),vals.end());
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        int i=0;
        while(i<vals.size()){
            int start=i;
            int end=vals.size()-1;
            int index = start;
            while(start<=end){
                int mid=(start+end)/2;
                if((mid-i+vals[i])==vals[mid]){
                    index=mid;
                    start=mid+1;
                } else {
                    end=mid-1;
                }
            }
            intervals.push_back({vals[i],vals[index]});
            i=index+1;
        }
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 
 
 2  3   6   9   4   11  14  10
 
 2  2


2   2

3   3

4   4

8   8

11  11
 
 */