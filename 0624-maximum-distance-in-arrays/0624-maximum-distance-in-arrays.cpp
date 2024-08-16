class Solution {
public:
    using pii=pair<int,int>;
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pii> maxHeap;
        for(int i=0;i<arrays.size();i++){
            if(maxHeap.size()<2){
                maxHeap.push({arrays[i][0],i});
            } else {
                if(maxHeap.top().first>arrays[i][0]){
                    maxHeap.pop();
                    maxHeap.push({arrays[i][0],i});
                }
            }
        }

        int ans=0;
        pii secondMin=maxHeap.top();
        maxHeap.pop();
        pii firstMin=maxHeap.top();

        for(int i=0;i<arrays.size();i++){
            if(firstMin.second==i){
                ans=max(ans,abs(secondMin.first-arrays[i].back()));
            } else {
                ans=max(ans,abs(firstMin.first-arrays[i].back()));
            }
        }
        return ans;
    }
};