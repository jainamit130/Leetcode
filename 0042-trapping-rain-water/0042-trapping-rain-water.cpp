class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> rightMax(n,0);
        for(int i=n-2;i>=0;i--) rightMax[i]=max(rightMax[i+1],height[i+1]);
        int leftMax = 0;
        int ans = 0;
        for(int i=1;i<n;i++) {
            leftMax = max(leftMax,height[i-1]);
            if(leftMax && rightMax[i]) ans += max(min(rightMax[i],leftMax)-height[i],0);
        }
        return ans;
    }
};

/*


0   1   0   2   1   0   1   3   2   1   2   1
0   1   2   3   4   5   6   7   8   9   10  11



*/