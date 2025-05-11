class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> mp(32,vector<int>(10));
        long long ans = 0;
        for(int i=0;i<n;i++) {
            int n = nums[i];
            int pos = 0;
            while(n) {
                int digit = n%10;
                ans += i-mp[pos][digit];
                mp[pos][digit]++;
                pos++;
                n/=10;
            }
        }
        return ans;
    }
};


/*




*/