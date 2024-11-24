class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        vector<int> prefix;
        prefix.push_back(0);
        for(int i=0;i<nums.size();i++) {
            prefix.push_back(prefix.back()+nums[i]);
        }

        int ans = INT_MAX;
        for(int i=1;i<=nums.size();i++) {
            for(int j=l;j<=r;j++) {
                if(i-j>=0 && i-j<nums.size()){
                    if(prefix[i]-prefix[i-j]>0)
                        ans = min(ans,prefix[i]-prefix[i-j]);
                }
            }
        }

        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};

/*

0   3   1   2   6


*/