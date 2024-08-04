class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> pq;
        int mod=1e9+7;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                pq.push_back(sum);
            }
        }   
        sort(pq.begin(),pq.end());
        int ans=0;
        for (int i=left-1;i<=right-1;i++){
            ans=(long long)ans%mod+(long long)pq[i]%mod;
        }
        return ans;
    }
};