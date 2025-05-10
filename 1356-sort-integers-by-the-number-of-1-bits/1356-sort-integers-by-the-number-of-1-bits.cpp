class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](auto& lhs,auto & rhs) {
            int count1 = __builtin_popcount(lhs);
            int count2 = __builtin_popcount(rhs);
            if(count1==count2) {
                return lhs<rhs;
            }
            return count1<count2;
        });
        return arr;
    }
};