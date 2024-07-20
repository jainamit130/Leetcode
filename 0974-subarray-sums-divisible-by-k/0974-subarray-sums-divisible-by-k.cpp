class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            nums[i]=sum%k;
        }

        unordered_map<int,int> mp;
        mp[0]=1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int val=nums[i]-k;
            if(nums[i]<0){
                val=nums[i]+k;
            }
            if(nums[i]==0){
                val=0;
            }
            if(mp.find(nums[i])!=mp.end()){
                ans+=mp[nums[i]];
            }
            if(val!=0){
                if(mp.find(val)!=mp.end()){
                    ans+=mp[val];
                }
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};