class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int nextKeyIndex = -1;
        int prevKeyIndex = -1;
        vector<int> kDistantIndices(nums.size(),-1);
        vector<int> ans;
        for(int i=nums.size()-1,j=0;i>=0;i--,j++) {
            if(nums[i]==key) nextKeyIndex=i;
            if(nums[j]==key) prevKeyIndex=j;
            if(nextKeyIndex!=-1 && abs(i-nextKeyIndex)<=k) {
                kDistantIndices[i]=i;
            } 
            if(prevKeyIndex!=-1 && abs(j-prevKeyIndex)<=k) {
               kDistantIndices[j]=j; 
            } 
        }
        for(auto n:kDistantIndices) {
            if(n!=-1) ans.push_back(n);
        }
        return ans;
    }
};