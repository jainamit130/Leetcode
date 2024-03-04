class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> prefix;
        prefix.push_back(0);
        for(int i=0;i<nums.size();i++){
            prefix.push_back(prefix.back()+nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(prefix[i]==prefix.back()-prefix[i+1])
                return i;
        }
        return -1;
    }
};