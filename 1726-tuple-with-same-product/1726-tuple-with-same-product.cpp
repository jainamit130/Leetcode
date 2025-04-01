class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(auto n:nums) {
            for(auto n1:nums) {
                if(n1!=n) {
                    ans += mp[n1*n];
                    mp[n1*n]++;
                }
            }
        }
        return ans-2;
    }
};

/*


12 -> 1

a   b   c   d
a   b   d   c

b   a   c   d
b   a   d   c


a   b   ef => 4
cd ef => 4 

*/