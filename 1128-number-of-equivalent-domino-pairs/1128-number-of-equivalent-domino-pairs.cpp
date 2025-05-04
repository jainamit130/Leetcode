class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int> mp;
        int ans = 0;
        for(auto domino:dominoes) {
            ans += mp[{min(domino[0],domino[1]),max(domino[0],domino[1])}];
            mp[{min(domino[0],domino[1]),max(domino[0],domino[1])}]++;
        }
        return ans;
    }
};