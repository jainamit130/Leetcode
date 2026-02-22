class Solution {
public:
    int binaryGap(int n) {
        int count = -1;
        int ans = 0;
        while(n) {
            if(n&1) {
                ans = max(ans,count+1);
                count = 0;
            } else if(count!=-1) {
                count++;
            }
            n = n>>1;
        }
        return ans;
    }
};
/*
1   0   0   0

*/