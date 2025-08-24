class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if(nums.size()%k!=0) return false;
        unordered_map<int,int> mp;
        int groups = nums.size()/k;
        for(auto n:nums) mp[n]++;
        unordered_map<int,int> mp2;
        for(auto [key,count]:mp) {
            mp2[count]++;
        }
        int formedGroups = 0;
        int remaining = 0;
        for(auto [count,size]:mp2) {
            // cout<<count<<" -> "<<size<<endl;
            int rem = (size*count)%k;
            formedGroups += (size*count)/k;
            if(count>groups) return false;
            if(rem!=0) {
                remaining += rem;
            }
        }
        return formedGroups+(remaining/k) == groups;
    }
};