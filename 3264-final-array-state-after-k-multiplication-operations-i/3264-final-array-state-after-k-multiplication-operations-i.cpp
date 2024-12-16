class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int n=nums.size();

        // O(n log n)
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        // O(k* log n)
        while(k){
            pq.push({pq.top()[0]*multiplier,pq.top()[1]});
            pq.pop();
            k--;
        }

        while(!pq.empty()){
            nums[pq.top()[1]]=pq.top()[0];
            pq.pop();
        }
        return nums;
    }
};