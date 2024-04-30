class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int xors = 0;
        unordered_map<int,int> mp;
        mp[xors]++;
        int ans=0;
        for(auto n:nums){
            xors=xors^n;
            if(mp.find(xors)!=mp.end())
                ans+=mp[xors];
            mp[xors]++;
        }
        return ans;
    }
};

/*

4   3   1   2   4
        i

Map

000
100
111
110
100
000



*/