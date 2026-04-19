class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++) {
            if(mp.find(nums[i])!=mp.end()) ans = min(ans,i-mp[nums[i]]);
                int rev = 0;
                int num = nums[i];
                while(num) {
                    rev = rev*10 + num%10;
                    num/=10;
                }
                mp[rev]=i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};