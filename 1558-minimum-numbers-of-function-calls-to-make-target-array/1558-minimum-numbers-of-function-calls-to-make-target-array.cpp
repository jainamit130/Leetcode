class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0,x= 0,y=0;
        for(auto i: nums){
            x = 0;
            while(i){
                x++;
                if(i&1)y++;
                i >>= 1;
            }
            ans = max(ans,x-1);
        }
        return ans+y;
    }
};