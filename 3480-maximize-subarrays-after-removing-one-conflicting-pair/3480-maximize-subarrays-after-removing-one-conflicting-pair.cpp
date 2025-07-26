class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int maxRest = 0, secondMaxRest = 0;
        long long maxExtra = 0;
        long long valid = 0;
        unordered_map<int,vector<int>> mp;
        for(auto pairs: conflictingPairs) {
            int smaller = min(pairs[0],pairs[1]), bigger = max(pairs[0],pairs[1]);
            mp[bigger].push_back(smaller);
        }
        vector<long long> extra(n+1,0);
        for(int i=1;i<=n;i++) {
            for(auto rest : mp[i]) {
                if(maxRest<=rest) {
                    secondMaxRest = maxRest;
                    maxRest = rest;
                } else if(secondMaxRest<rest) {
                    secondMaxRest = rest;
                }
            }
            valid += (i-maxRest);
            extra[maxRest]+=maxRest-secondMaxRest;
            maxExtra = max(maxExtra,extra[maxRest]);
        }
        return valid + maxExtra;
    }
};