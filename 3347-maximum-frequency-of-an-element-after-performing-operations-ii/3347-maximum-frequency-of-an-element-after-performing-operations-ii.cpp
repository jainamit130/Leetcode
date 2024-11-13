class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int,int> updates;
        unordered_map<int,int> freq;
        int mini = 2e9;
        int maxi = -2e9;
        for(auto n:nums) {
            freq[n]++;
            mini = min(mini,n-k);
            maxi = max(maxi,n+k);
            updates[n-k]++;
            updates[n+k+1]--;
            updates[n]+=0;
        }

        int ans = 0;
        int prevUpdate = 0;
        for(auto itr = updates.begin(); itr!=updates.end(); itr++){
            itr->second+=prevUpdate;
            prevUpdate = itr->second; 
            int subAns = itr->second-freq[itr->first];
            subAns = min(subAns,numOperations)+freq[itr->first];
            ans = max(ans,subAns);
        }
        return ans;
    }
};