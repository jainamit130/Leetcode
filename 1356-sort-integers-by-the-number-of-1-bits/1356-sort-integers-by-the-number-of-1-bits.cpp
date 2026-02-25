class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](auto& lhs,auto& rhs) {
            int a = __builtin_popcount(lhs);
            int b = __builtin_popcount(rhs);
            if(a==b) return lhs<rhs;
            return a<b;
        });
        return arr;
    }
};