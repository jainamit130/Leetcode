class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int mod = 1e9+7;
        vector<int> dp;
        vector<int> prefix(2,0);
        prefix[1]=1;
        deque<int> minDq,maxDq;
        int index = -1;
        for(int i=0;i<nums.size();i++) {
            // Add this number to mindq (should always be strictly increasing order)
            while(!minDq.empty() && nums[minDq.back()]>=nums[i]) {
                minDq.pop_back();
            } 
            minDq.push_back(i);
            // Add this number to maxdq (should always be strictly decreasing order)
            while(!maxDq.empty() && nums[maxDq.back()]<=nums[i]) {
                maxDq.pop_back();
            } 
            maxDq.push_back(i);
            // get a valid state
            while(nums[maxDq.front()]-nums[minDq.front()]>k) {
                index = max(index,min(maxDq.front(),minDq.front()));
                if(maxDq.front()<minDq.front()) maxDq.pop_front();
                else minDq.pop_front();
            }
            dp.push_back((prefix.back()-prefix[index+1]+mod)%mod);
            prefix.push_back((dp.back()*1LL+prefix.back())%mod);
        }
        return dp.back();
    }
};