class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int> mp2;
            if((nums[i]&k)==k){
                mp2[nums[i]]++;
                for(auto [n,count]: mp1){
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

2       1        2       4       0

010     001     010     100     000


000

*/