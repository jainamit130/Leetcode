class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k>0){
            int m=pq.top();
            pq.pop();
            while(k && m<=pq.top()){
                m++;
                k--;
            }
            pq.push(m);
        }
        long long prod=1;
        while(!pq.empty()){
            prod=(prod*pq.top())%((int)1e9+7);
            pq.pop();
        }
        return prod%((int)1e9+7);
    }
};