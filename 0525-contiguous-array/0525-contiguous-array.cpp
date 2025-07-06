class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> count01;
        int count0=0;
        int count1=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                count0++;
            else
                count1++;
            if(count01.find(count1-count0)==count01.end())
                count01[count1-count0]=i;
            if(count1==count0)
                ans=count1+count0;
            else 
                ans=max(ans,i-count01[count1-count0]);
        }
        return ans;
    }
};