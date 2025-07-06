class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mpIndexes;
        for(int i=0;i<nums.size();i++) {
            mpIndexes[nums[i]].push_back(i);
        }

        vector<int> divisors;
        for(int i=1;i*i<=k;i++) {
            if(k%i==0) divisors.push_back(i);
            if(i!=k/i) divisors.push_back(k/i);
        }
        int ans = 0;
        for(auto [val,indexes]:mpIndexes) {
            unordered_map<int,int> mp;
            for(auto index:indexes) {
                int gcdd = gcd(index,k);
                int remainingFactor = k/gcdd;
                ans += mp[remainingFactor];
                for(auto d:divisors) {
                    if(index%d==0) mp[d]++;
                }
            }
        }
        return ans;
    }
};


/*
0   1   2   3   4   5   6
3   1   2   2   2   1   3

k = 6

0 => 1,2,3,4,5,6
1 => 2,4,6
2 => 3,4,5,6
3 => 4,6
4 => 5,6
5 => 6
6 => 
*/