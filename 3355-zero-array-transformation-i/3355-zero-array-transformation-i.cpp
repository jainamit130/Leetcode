class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n+1);
        for(auto q:queries) {
            prefix[q[0]]++;
            prefix[q[1]+1]--;
        }

        for(int i=1;i<=n;i++){
            prefix[i]+=prefix[i-1];
            if(prefix[i-1]<nums[i-1]){
                return false;
            }
        }
        return true;
    }
};


/*

Query = [2,5]

0   1   2   3   4   5   6   
2   5   9   4   1   0   3

0   0   0   0   0   0   0
0   0   1   0   0   0   -1
0   0   1   1   1   1   0




*/