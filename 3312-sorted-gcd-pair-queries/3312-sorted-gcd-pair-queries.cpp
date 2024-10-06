class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size();
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
            gcdPairs[i]=(long long)(countAsDivisor[i]*(countAsDivisor[i]-1)/2);
            for(int j=2*i;j<=maxEle;j+=i){
                gcdPairs[i]-=gcdPairs[j];
            }
        }

        vector<long long> gcdPrefix;
        gcdPrefix.push_back(0);
        for(int i=1;i<gcdPairs.size();i++){
            gcdPrefix.push_back(gcdPrefix.back()+gcdPairs[i]);
        }

        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(upper_bound(gcdPrefix.begin(),gcdPrefix.end(),queries[i])-gcdPrefix.begin());
        }
        return ans;
    }
};


/*

        i
2   4   8   16  16  64

2   4   8   16  64
1   1   1   2   1
5   4   3   2   1

1   2   3   4 = x(x-1)/2 = xC2


gcdPairs[i] == how many pairs are there which will have a gcd of i
gcdPairs[8] = every possible pair in the given nums which is 8 or multiple of 8 - 
              every possible pair in the given nums which is 16 or multiple of 16 -  
              every possible pair in the given nums which is 24 or multiple of 24 -
              every possible pair in the given nums which is 32 or multiple of 32 -
              every possible pair in the given nums which is 40 or multiple of 40 -
              every possible pair in the given nums which is 48 or multiple of 48 -
              every possible pair in the given nums which is 56 or multiple of 56 -
              every possible pair in the given nums which is 64 or multiple of 64 - = 6 - 3 = 3



8,16 = 8
8,16 = 8
8,64 = 8
16,16 = 16
16,64 = 16
16,64 = 16




1   2   3   4
3   2   0   1

0   1   2   3   4
0   3   5   5   6




*/