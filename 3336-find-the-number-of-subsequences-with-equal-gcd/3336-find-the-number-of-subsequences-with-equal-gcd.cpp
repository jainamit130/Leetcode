class Solution {
public:
    int mod = 1e9+7;
    vector<vector<vector<int>>> cache;
    int subsequencePairCount(vector<int>& nums) {
        cache.resize(nums.size()+1,vector<vector<int>>(202,vector<int>(202,-1)));
        return solve(nums,0,-1,-1);
    }

    int solve(vector<int>& nums,int index,int gcd1,int gcd2){
        if(index>=nums.size()){
            return gcd1!=-1 && gcd1==gcd2;
        }
        
        if(cache[index][gcd1+1][gcd2+1]!=-1){
            return cache[index][gcd1+1][gcd2+1];
        }

        int set1 = 0;
        int set2 = 0;
        int skipped = 0;
        if(gcd1==-1){
            set1=solve(nums,index+1,nums[index],gcd2);
        } else {
            set1=solve(nums,index+1,gcd(gcd1,nums[index]),gcd2);
        }

        if(gcd2==-1){
            set2=solve(nums,index+1,gcd1,nums[index]);
        } else {
            set2=solve(nums,index+1,gcd1,gcd(gcd2,nums[index]));
        }

        skipped=solve(nums,index+1,gcd1,gcd2);
        cache[index][gcd1+1][gcd2+1]=(1LL*set1+1LL*set2+1LL*skipped)%mod;
        return cache[index][gcd1+1][gcd2+1];
    }
};