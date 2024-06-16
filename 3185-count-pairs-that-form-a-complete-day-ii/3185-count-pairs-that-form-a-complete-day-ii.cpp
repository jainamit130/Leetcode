class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        unordered_map<int, int> mp;
        for(auto h: hours){
            ans += mp[(24 - h%24)%24];
            mp[h%24]++;
    }
    return ans;
}
};



/*

12  16  12
0   12  28  40

0   12  4   16


12  12  30  24  24


12  24  54  78  102

0   12  0   6   6   6




72  48  24  3

0   72  120  144    147

0   0   0      0    3

*/