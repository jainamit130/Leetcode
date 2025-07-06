class Solution {
public:
    int maxScore(string s) {
        int count1 = 0;
        for(auto ch:s) {
            if(ch=='1')
                count1++;
        }
        int count0=0;
        int ans = count1-1;
        for(auto ch:s) {
            if(ch=='0') {
                count0++;
            } else {
                count1--;
            }
            ans = max(ans,count0+count1);
        }
        return ans;
    }
};