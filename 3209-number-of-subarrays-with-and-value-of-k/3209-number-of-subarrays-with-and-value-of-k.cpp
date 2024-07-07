class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        unordered_map<int,int> mp1;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int> mp2;
            if((nums[i]&k)==k){
                mp2[nums[i]]++;
                for(auto [n,count]:mp1){
                    mp2[n&nums[i]]+=count;
                }
                ans+=mp2[k];
            }
            mp1=mp2;
        }
        return ans;
    }
};


/*

1   2   2   1   3
                i


3 & 2 =2
Map
3->1

k=2
Ans+=Map[k=2]=1+Map[k=2]=1+2=3



*/