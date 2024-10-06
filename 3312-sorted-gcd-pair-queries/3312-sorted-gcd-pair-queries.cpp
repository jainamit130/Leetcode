class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(),nums.end());

        vector<int> freq(maxEle+1);
        vector<int> countAsDivisor(maxEle+1);

        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }

        for(int i=1;i<=maxEle;i++){
            for(int j=i;j<=maxEle;j+=i){
                countAsDivisor[i]+=freq[j];
            }
        }
        vector<long long> gcdPairs(maxEle+1);
        for(int i=maxEle;i>=1;i--){
            gcdPairs[i]=1LL*countAsDivisor[i]*(countAsDivisor[i]-1)/2;
            for(int j=2*i;j<=maxEle;j+=i){
                gcdPairs[i]-=gcdPairs[j];
            }
        }
        
        vector<long long> prefixGcdPairsWithGcds(maxEle + 1);
        for (int i = 1; i <= maxEle; ++i) {
            prefixGcdPairsWithGcds[i] = prefixGcdPairsWithGcds[i-1]+gcdPairs[i];
        }

        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(upper_bound(prefixGcdPairsWithGcds.begin(),prefixGcdPairsWithGcds.end(),queries[i])-prefixGcdPairsWithGcds.begin());
        }

        return ans;
    }
};