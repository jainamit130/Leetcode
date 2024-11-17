class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix;
        prefix.push_back(0);
        suffix.push_back(0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j = n-1-i;
            prefix.push_back(prefix.back()+nums[i]);
            suffix.push_back(suffix.back()+nums[j]);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int j = n-i-1;
            if(nums[i]==0){
                if(abs(prefix[i+1]-suffix[j+1])<=1){
                    ans++;
                }
                if(prefix[i+1]==suffix[j+1]){
                    ans++;
                }
            }
        }
        return ans;
    }
};


/*

    1   0   2   0   3

0   1   1   3   3   6

0   3   3   5   5   6


*/