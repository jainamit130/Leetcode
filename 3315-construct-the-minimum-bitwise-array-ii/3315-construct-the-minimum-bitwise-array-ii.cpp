class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(auto n:nums){
            int subAns=-1;
            for(int i=30;i>=0;i--){
                if(n&(1<<i)){
                    int x = n&(~(1<<i));
                    if((x|(x+1))==n){
                        subAns=x;
                        break;
                    }
                }
            }
            ans.push_back(subAns);
        }
        return ans;
    }
};
