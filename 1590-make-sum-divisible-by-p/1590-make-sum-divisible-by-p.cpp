class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int> mp;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum=sum+(long long)nums[i]%p;
        } 
        int target = sum%p;
        if(target==0){
            return 0;
        }
        int currSum=0;
        mp[0]=-1;
        int ans = nums.size();
        for(int i=0;i<nums.size();i++){
            currSum += (long long)nums[i]%p;
            int n = ((long long)currSum - target + p)%p;
            if(mp.find(n)!=mp.end()){
                ans=min(i-mp[n],ans);
            }
            mp[currSum%p]=i;
        }

        if(ans==nums.size()){
            return -1;
        }
        return ans;
    }
};

/*

6   3   5   2
9


*/