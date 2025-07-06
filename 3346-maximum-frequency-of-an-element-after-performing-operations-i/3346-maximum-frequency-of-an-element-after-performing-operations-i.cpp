class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> updates;
        unordered_map<int,int> freq;
        int mini = 1e9;
        int maxi = -1e9;
        for(auto n:nums) {
            freq[n]++;
            mini = min(mini,n-k);
            maxi = max(maxi,n+k);
            updates[n-k]++;
            updates[n+k+1]--;
        }

        int ans = 0;
        for(int i=mini;i<=maxi;i++){
            updates[i]+=updates[i-1];
            int subAns = updates[i]-freq[i];
            subAns = min(subAns,numOperations)+freq[i];
            ans = max(ans,subAns);
        }
        return ans;
    }
};