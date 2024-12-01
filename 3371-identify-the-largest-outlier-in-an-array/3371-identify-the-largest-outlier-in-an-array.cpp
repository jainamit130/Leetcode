class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        unordered_map<int,int> mp;
        for(auto n:nums) {
            mp[n]++;
        }
        int ans = INT_MIN;
        for(auto n:nums) {
            int twice = (total - n);
            if(twice%2==0){
                if(mp.find(twice/2)!=mp.end()){
                    if((n==twice/2 && mp[twice/2]>1) || n!=twice/2) {
                        ans = max(ans,n);
                    } 
                }
            }
        }
        return ans;
    }
};

/*

2   3   5   10


-x1  -x2  -x3  -x4   y1   y2   y3   y4





*/