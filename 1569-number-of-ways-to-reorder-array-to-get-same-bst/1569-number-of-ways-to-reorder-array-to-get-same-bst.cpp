class Solution {
public:
    int MOD=1e9+7;
    using ll=long long;
    vector<vector<ll>> pascal;
    int numOfWays(vector<int>& nums) {
        constructPascal(nums.size()+1);
        return (solve(nums)-1)%MOD;
    }

    int solve(vector<int>& nums){
        if(nums.size()<3){
            return 1;
        }

        vector<int> low;
        vector<int> high;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[0])
                low.push_back(nums[i]);
            if(nums[i]>nums[0])
                high.push_back(nums[i]);
        }
        
        ll x=solve(low) % MOD;
        ll y=solve(high) % MOD;
        ll z=pascal[nums.size()-1][low.size()]%MOD;
        return (((x*y)%MOD)*z)%MOD;
    }

    void constructPascal(int n) {
        pascal.resize(n+1,vector<ll>(n+1));
        for(int i=0;i<=n;i++){
            pascal[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                pascal[i][j]=(ll)pascal[i-1][j]+(ll)pascal[i-1][j-1];
            }
        }
        return;
    }

};