class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count=0;
        for(auto n:nums){
            if(n)
                count++;
        }

        int i=0,j=0;
        int c1=0;
        int ans=INT_MAX;
        int flag=-1;
        while(i<nums.size()){
            if(j>=nums.size()){
                flag=0;
            }
            j=j%nums.size();
            if(nums[j]==1){
                c1++;
            }
            if((j-i+1<count) && (flag==-1)){
                j++;
            } else {
                ans=min(ans,count-c1);
                if(nums[i]==1){
                    c1--;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};



/*

0   1   0   1   1   0   0

i
j




*/