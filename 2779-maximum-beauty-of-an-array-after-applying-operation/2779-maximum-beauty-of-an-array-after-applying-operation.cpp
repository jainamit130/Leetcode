class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> line(3e5+1);
        for(auto n:nums) {
            line[n-k+1e5+1]++;
            line[n+k+1+1e5+1]--;
        }
        int ans = 0;
        int prefix = 0;
        for(auto l:line) {
            prefix+=l;
            ans = max(ans,prefix);
        }
        return ans;
    }
};


/*

4   6   1   2

2   4   -1  0
6   8   3   4

4   4   1   4

-1,1 -> 2
2,3 -> 3
4,4 -> 3
5,6 -> 2


*/