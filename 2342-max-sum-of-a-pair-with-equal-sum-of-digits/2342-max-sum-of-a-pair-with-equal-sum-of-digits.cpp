class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> mp;
        for(auto n:nums) {
            int sum = 0;
            int originalNum = n; 
            while(n) {
                sum += n%10;
                n/=10;
            }
            mp[sum].push(originalNum);
            if(mp[sum].size()>2) {
                mp[sum].pop();
            }
        }

        for(auto [_,heap]:mp) {
            int sum = 0;
            if(heap.size()==2) {
                while(!heap.empty()) {
                    sum+=heap.top();
                    heap.pop();
                }
                ans = max(ans,sum);
            }
        }
        return ans;
    }
};