class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> maxDiff;
        int n=nums.size();
        for(int i=0;i<n/2;i++){
            int a=nums[i];
            int b=nums[n-i-1];
            int diff=abs(a-b);
            mp[diff]++;
            int maxAtt=max(max(a,b),max(k-b,k-a));
            maxDiff.push_back(maxAtt);
        }

        sort(maxDiff.begin(),maxDiff.end());
        int ans=INT_MAX;
        for(auto [a,b]:mp){
            int lesser=lower_bound(maxDiff.begin(),maxDiff.end(),a)-maxDiff.begin();
            int greater=(n/2)-lesser;
            ans=min(ans,greater-b+2*lesser);
        }
        return ans;
    }
};