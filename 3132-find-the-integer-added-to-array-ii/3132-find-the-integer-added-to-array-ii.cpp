class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(auto n:nums1)
            mp[n]++;
        unordered_map<int,int> mpcopy;
        int ans=INT_MAX;
        int result=INT_MAX;
        for(int i=-1000;i<=1000;i++){
            int flag=0;
            mpcopy=mp;
            for(int j=0;j<nums2.size();j++){
                int n=nums2[j]+i;
                if(mpcopy.find(n)==mpcopy.end()){
                    flag=1;
                    break;
                } else {
                    mpcopy[n]--;
                    if(mpcopy[n]==0)
                        mpcopy.erase(n);
                }
            }
            if(flag==0){
                ans=min(ans,abs(i));
                result=i;
            }
        }
        return -result;
    }
};

/*

nums1: 8    11  13  14  19
nums2: 7    12  13


*/