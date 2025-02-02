class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;
        int n = startTime.size();
        if(startTime[0]>0) minHeap.push({startTime[0],0,startTime[0]});
        for(int i=1;i<n;i++) {
            minHeap.push({startTime[i]-endTime[i-1],endTime[i-1],startTime[i]});
            if(minHeap.size()>3) {
                minHeap.pop();
            }
        }
        minHeap.push({eventTime-endTime.back(),endTime.back(),eventTime});
        if(minHeap.size()>3) {
            minHeap.pop();
        }

        vector<vector<int>> gaps;
        while(!minHeap.empty()) {
            gaps.push_back(minHeap.top());
            minHeap.pop();
        }

        int ans = 0;
        for(int i=0;i<n;i++) {
            int upperBound = eventTime;
            if(i<n-1) upperBound = startTime[i+1];
            int lowerBound = 0;
            if(i>0) lowerBound = endTime[i-1];
            int meetDuration = endTime[i]-startTime[i];
            // Slide to left or right
            ans = max(ans,upperBound-lowerBound-meetDuration);
            // Take Box away to some OTHER gap
            for(auto gap:gaps) {
                if((gap[1]>=upperBound || gap[2]<=lowerBound) && gap[0]>=meetDuration) {
                    ans = max(ans,upperBound-lowerBound);
                }
            }
        }
        return ans;
    }
};