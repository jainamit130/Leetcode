class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int count1=0;
            for(auto n:nums){
                if((1<<i)&n){
                    count1++;
                }
            }
            if(count1%3)
                ans=ans|(1<<i);
        }
        return ans;
    }
};


/*

2   2   3   2


*/