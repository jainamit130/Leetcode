class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queriess) {
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>> queries(queriess.size());
        for(int i=0;i<queriess.size();i++){
            queries[i]={queriess[i],i};
        }
        sort(queries.begin(),queries.end());
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;
        int j=1;
        int i=0;
        vector<int> ans(queries.size(),-1);
        minHeap.push({intervals[0][1]-intervals[0][0]+1,intervals[0][1]});
        while(i<queries.size()){
            while(j<intervals.size() && intervals[j][0]<=queries[i].first){
                minHeap.push({intervals[j][1]-intervals[j][0]+1,intervals[j][1]});
                j++;
            }

            while(!minHeap.empty() && minHeap.top()[1]<queries[i].first){
                minHeap.pop();
            }

            if(!minHeap.empty())
                ans[queries[i].second]=minHeap.top()[0];
            i++;
        }
        return ans;
    }
};