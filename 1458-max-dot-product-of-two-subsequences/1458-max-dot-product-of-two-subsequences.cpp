class Solution {
public:
    vector<vector<vector<int>>> cache;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        cache.resize(nums1.size()+1,vector<vector<int>>(nums2.size()+1,vector<int>(2,-1)));
        return solve(nums1,nums2,0,0,0);
    }

    int solve(vector<int>& nums1,vector<int>& nums2,int index1,int index2,int flag) {
        if(index1>=nums1.size() || index2>=nums2.size()) return flag?0:INT_MIN;
        if(cache[index1][index2][flag]!=-1) return cache[index1][index2][flag];
        int ans = INT_MIN;
        ans = max(ans,solve(nums1,nums2,index1+1,index2,flag));
        ans = max(ans,solve(nums1,nums2,index1,index2+1,flag));
        ans = max(ans,nums1[index1]*nums2[index2]+solve(nums1,nums2,index1+1,index2+1,1));
        return cache[index1][index2][flag]=ans;
    }
};