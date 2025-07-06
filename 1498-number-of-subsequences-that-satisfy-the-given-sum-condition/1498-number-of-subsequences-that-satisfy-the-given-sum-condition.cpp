class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mod = 1e9+7;
        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            int search = target - nums[i];
            if(search>=nums[i]) {
                int index = upper_bound(begin(nums),end(nums),search)-nums.begin();
                ans = (ans + modpow(2, index - i - 1, mod)) % mod;
            }
        }
        return ans;
    }

    int modpow(int base, int exp, int mod) {
        int result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1)
                result = (1LL * result * base) % mod;
            base = (1LL * base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

};


/*

12
2   3   3   4   6   7

32 + 16 + 8 + 4 + 2 = 

*/