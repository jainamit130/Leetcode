class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool flipped=false;
        int ans=0;
        if(nums[0]==0){
            ans++;
        }
        for(int i=1;i<nums.size();i++){
            if(flipped){
                nums[i]=!nums[i];
            }
            if(nums[i]!=nums[0]){
                flipped=!flipped;
                ans++;
            }
        }
        return ans;
    }
};

/*

0,1,1,0,1

0   0   0   1   0

0   0   0   0   1

0   0   0   0   0

1   1   1   1   1


*/