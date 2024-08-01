class RangeModule {
public:
    vector<vector<int>> intervals;
    int binarySearch(int left){
        int start=0,end=intervals.size()-1;
        while(start<end){
            int mid=(start+end)/2;
            if(intervals[mid][0]<left){
                start=mid+1;
            } else if(intervals[mid][0]==left){
                end=mid;
                break;
            } else {
                end=mid-1;
            }
        }
        return end;
    }

    void printIntervals(){
        for(int i=0;i<intervals.size();i++){
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        }
        return;
    }

    void mergeIntervals(){
        int i=0;
        while(i<intervals.size()-1){
            int second=intervals[i][1];
            int first=intervals[i][0];
            while(i+1<intervals.size() && second>=intervals[i+1][0]){
                second=max(intervals[i+1][1],second);
                first=min(intervals[i+1][0],first);
                intervals.erase(intervals.begin()+i+1);
            }
            intervals[i][0]=first;
            intervals[i][1]=second;
            i++;
        }
        return;
    }

    RangeModule() {
    }
    
    void addRange(int left, int right) {
        // cout<<"Add Intervals: "<<left<<" , "<<right<<" -> ";
        int indexToAppend=binarySearch(left);
        // cout<<indexToAppend<<endl;
        if(indexToAppend==-1){
            if(intervals.size()==0)
            intervals.push_back({left,right});
            else{
            intervals.insert(intervals.begin(),{left,right});
            // printIntervals();
            // cout<<"-------------"<<endl;
            mergeIntervals();
            }
        } else {
            if(intervals[indexToAppend][0]>=left)
            intervals.insert(intervals.begin()+indexToAppend,{left,right});
            else
            intervals.insert(intervals.begin()+indexToAppend+1,{left,right});
            // printIntervals();
            // cout<<"-------------"<<endl;
            mergeIntervals();
        }
        // printIntervals();
        return;
    }
    
    bool queryRange(int left, int right) {
        // cout<<"Query Range : "<<left<<","<<right<<" -> index: ";
        int index=binarySearch(left);
        // cout<<index<<endl;
        if(index==-1)
            return false;
        else
            if(index>0)
            return (intervals[index-1][0]<=left && intervals[index-1][1]>=right) || (intervals[index][0]<=left && intervals[index][1]>=right);
        return intervals[index][0]<=left && intervals[index][1]>=right;
    }
    
    void removeRange(int left, int right) {
        vector<vector<int>> res;
        int i=0;
        // cout<<"Remove Intervals: "<<left<<" , "<<right<<endl;
        while(i<intervals.size()){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(right<=start || left>=end){
                res.push_back({start,end});
            } else if(left<=start && right>=end){
                i++;
                continue;
            } else if(left<start){
                res.push_back({right,end});
            } else if(right>end){
                res.push_back({start,left});
            } else{
                if(start<left)
                    res.push_back({start,left});
                if(right<end)
                    res.push_back({right,end});
            } 
            i++;
        }
        intervals=res;
        // printIntervals();
        return;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */


 /*
 
 Add Interval

 Binary Search - to get the position where it needs to be inserted that is find index i such that
 interval[i]<=left O(log N)

 Insert the interval and then merge the interval => O(N) + O(N)
 

 Remove Interval

 4 Cases

 1st Case=> Not Present in interval => ignore interval
 2nd Case=> Overlap l/R => shorten the interval
 3rd Case=> Out of Range => Remove Interval
 4th Case=> Completely within the interval => Break the interval

 Query Interval

 Binary Search => find the index i such that 
 interval[i]<=left O(log N)
 and find the right index if within or not and answer accordingly
 */