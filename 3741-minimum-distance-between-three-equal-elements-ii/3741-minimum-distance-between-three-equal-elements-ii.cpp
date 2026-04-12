class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,queue<int>> mp;
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++) {
            if(mp.find(nums[i])!=mp.end() && mp[nums[i]].size()==3) mp[nums[i]].pop();
            mp[nums[i]].push(i);
            if(mp[nums[i]].size()==3) {
                queue<int> temp = mp[nums[i]];
                int a = temp.front();temp.pop();
                int b = temp.front();temp.pop();
                int c = temp.front();temp.pop();
                ans = min(ans,b-a+c-a+c-b);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};