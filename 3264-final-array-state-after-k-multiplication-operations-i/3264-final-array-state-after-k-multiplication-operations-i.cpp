class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
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