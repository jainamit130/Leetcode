class Solution {
public:
    using pii = pair<int,int>;
    long long maximumProduct(vector<int>& nums, int m) {
        priority_queue<pii,vector<pii>,greater<pii>> minHeap;
        priority_queue<pii> maxHeap;
        for(int i=m-1;i<nums.size();i++) {
            minHeap.push({nums[i],i});
            maxHeap.push({nums[i],i});
        }
        long long ans = LLONG_MIN;
        for(int i=0;i<=nums.size()-m;i++) {
            if(nums[i]<0) {
                // get min element from min Heap
                while(!minHeap.empty() && i+m-1>minHeap.top().second) {
                    minHeap.pop();
                }
                ans = max(1LL*ans,minHeap.top().first*1LL*nums[i]);
            } else {
                // get max element from max Heap
                while(!maxHeap.empty() && i+m-1>maxHeap.top().second) {
                    maxHeap.pop();
                }
                ans = max(1LL*ans,maxHeap.top().first*1LL*nums[i]);
            }
        }
        return ans;
    }
};