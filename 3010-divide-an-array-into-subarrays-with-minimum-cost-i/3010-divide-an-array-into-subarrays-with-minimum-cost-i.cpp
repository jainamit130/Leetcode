class Solution {
public:
    int minimumCost(vector<int>& nums) {
        priority_queue<int> pq;
        for(int i=1;i<nums.size();i++) {
            int n = nums[i];
            pq.push(n);
            if(pq.size()>2) pq.pop();
        }
        int ans = nums[0];
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};