class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int mx=0;
        vector<vector<int>> cache(nums.size()+1,vector<int>(1500,0));
        for(int i=1;i<=nums.size();++i)
        {
            for(int j=i-1;j>0;--j)
            {
                int d = nums[j-1]-nums[i-1]<0 ? 500+abs(nums[j-1]-nums[i-1]):nums[j-1]-nums[i-1];
                if(cache[j][d]==0)
                  cache[j][d]=1;
                cache[i][d]=max(cache[i][d],1+cache[j][d]);
                mx=max(mx,cache[i][d]);
            }
        }
        return mx;
    }
};