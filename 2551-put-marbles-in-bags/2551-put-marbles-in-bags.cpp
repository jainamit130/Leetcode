class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> minHeapForMaxValues;
        priority_queue<long long> maxHeapForMinValues;
        for(int i=0;i<weights.size()-1;i++) {
            minHeapForMaxValues.push(1LL*weights[i+1]+weights[i]);
            maxHeapForMinValues.push(1LL*weights[i+1]+weights[i]);
            if(minHeapForMaxValues.size()>k-1) minHeapForMaxValues.pop();
            if(maxHeapForMinValues.size()>k-1) maxHeapForMinValues.pop();
        }
        long long ans = 0;
        while(!maxHeapForMinValues.empty()) {
            ans += minHeapForMaxValues.top();
            minHeapForMaxValues.pop();
            ans -= maxHeapForMinValues.top();
            maxHeapForMinValues.pop();
        }
        return ans;
    }
};