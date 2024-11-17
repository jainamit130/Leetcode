class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int size = nums.size();
        vector<int> prefix(size+1);
        for(auto query:queries) {
            prefix[query[0]]++;
            prefix[query[1]+1]--;
        }

        for(int i=1;i<=size;i++){
            prefix[i]+=prefix[i-1];
            if(prefix[i-1]<nums[i-1]){
                return false;
            }
        }
        return true;
    }
};