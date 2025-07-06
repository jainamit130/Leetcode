class Solution {
public: 
    vector<vector<long long>> cache;
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        vector<long long> costs;
        vector<long long> prefix;
        cache.resize(nums.size()+1,vector<long long>(nums.size()+1,-1));
        costs.push_back(0);
        prefix.push_back(0);
        for(int i=0;i<nums.size();i++) {
            costs.push_back(costs.back()+cost[i]);
            prefix.push_back(prefix.back()+nums[i]);
        }
        for(auto n:nums) {
        }
        return solve(nums,prefix,costs,0,1,k);
    }

    long long solve(vector<int>& nums,vector<long long>& prefix,vector<long long>& costs,int index,int order,int k) {
        if(index>=nums.size()) return 0;
        if(cache[index][order]!=-1) return cache[index][order];
        long long ans = LLONG_MAX;
        for(int i=index;i<nums.size();i++) {
            ans = min(ans,(prefix[i+1]+1LL*order*k)*(costs[i+1]-costs[index])+solve(nums,prefix,costs,i+1,order+1,k));
        }
        return cache[index][order]=ans;
    }
};