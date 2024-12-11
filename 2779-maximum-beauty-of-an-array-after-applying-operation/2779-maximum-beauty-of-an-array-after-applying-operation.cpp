class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int maxE = INT_MIN;
        int minE = INT_MAX;
        for(auto n:nums) {
            maxE=max(maxE,n+k);
            minE=min(minE,n-k);
        }

        vector<int> line(4e5+1);
        for(auto n:nums) {
            cout<<n-k+abs(minE)<<endl;
            line[n-k+abs(minE)]++;
            line[n+k+1+abs(minE)]--;
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