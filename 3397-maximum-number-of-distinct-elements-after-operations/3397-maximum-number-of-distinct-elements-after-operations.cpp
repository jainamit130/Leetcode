class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int last = INT_MIN;
        int ans = 0;
        for(auto n:nums) {
            if(last+1<=n+k) {
                ans++;
                last = max(last+1,n-k);
            }
        }
        return ans;
    }
};


/*

-k to k = -2 to 2

1   2   2   3   3   4
1   2   0   3   4   5     
        1       1   1




-1    0     0     1     1     2
3     4     4     5     5     6



*/


