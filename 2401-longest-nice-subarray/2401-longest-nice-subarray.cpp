class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=0,j=0;
        vector<int> bits(32);
        int ans = 1;
        while(j<nums.size()) {
            while(j<nums.size() && isValid(bits)) {
                int n = nums[j];
                int pos = 0;
                while(n) {
                    bits[pos] += n&1; 
                    n=n>>1;
                    pos++;
                }
                ans = max(ans,j-i);
                j++;
            }

            if(isValid(bits)) {
                ans = max(ans,j-i);
            }

            while(i<j && !isValid(bits)) {
                int n = nums[i];
                int pos = 0;
                while(n) {
                    bits[pos] -= n&1; 
                    n=n>>1;
                    pos++;
                }
                i++;
            }
        }
        return ans;
    }

    bool isValid(vector<int>& bits) {
        for(auto bit:bits) {
            if(bit>1) return false;
        }
        return true;
    }
};

/*

0   1   0   1   0   0   0   0   1   1   0   1   0   0   0   1   0   0   0   1   1   0   0   0   1   1   0   0   0   0
0   1   1   1   1   1   0   1   0   0   1   1   0   0   0   0   1   0   1   1   0   1   0   1   0   1   1   0   1   0   
0   0   0   0   0   1   0   0   1   0   0   1   0   1   0   0   1   0   1   0   1   0   1   0   0   0   0   0   1   1
0   0   1   1   0   0   1   0   1   1   1   1   0   1   1   0   0   1   1   1   0   0   1   0   1   1   1   0   0   1
0   1   0   0   1   1   0   0   1   0   1   0   1   1   0   1   1   0   1   1   0   1   1   1   1   1   1   0   1   1
1   0   0   0   0   0   1   1   1   1   1   0   1   0   0   1   0   0   0   1   0   0   0   1   1   0   0   0   1   1
0   0   1   0   1   1   0   1   0   1   1   1   1   1   1   1   1   1   0   0   0   1   1   1   0   0   0   0   0   1
1   0   0   0   0   0   1   0   1   1   0   0   1   1   0   1   1   0   0   1   1   0   1   0   0   0   1   0   1   0
1   0   1   1   1   1   0   1   0   0   1   1   0   0   1   0   0   1   0   0   0   0   1   1   0   0   0   0   0   1
0   0   1   1   1   0   1   0   0   0   1   0   1   0   0   0   1   0   1   1   1   0   1   0   1   1   0   0   1   1


*/