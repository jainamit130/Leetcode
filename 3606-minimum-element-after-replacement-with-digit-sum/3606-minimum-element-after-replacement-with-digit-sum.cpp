class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(auto n:nums){
            int sum=0;
            while(n){
                sum+=n%10;
                n/=10;
            }
            ans=min(ans,sum);
        }
        return ans;
    }
};