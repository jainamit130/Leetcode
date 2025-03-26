class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int sum = 0;
        vector<int> nums;
        int rem = grid[0][0]%x;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                sum+=grid[i][j];
                if(grid[i][j]%x!=rem) {
                    return -1;
                }
                nums.push_back(grid[i][j]);
            }
        }
        int ans = 0;
        sort(nums.begin(),nums.end());
        int median = nums[nums.size()/2];
        for(auto n : nums) {
            ans += abs(median - n) / x;
        }
        return ans;
    }
};

/*

1   3   9   15


*/