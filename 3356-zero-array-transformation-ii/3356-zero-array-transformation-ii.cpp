class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int start=0;
        int end = queries.size()-1;
        int ans = -1;
        while(start<=end) {
            int mid = (start+end)/2;
            vector<int> prefix(n+1);
            for(int i=0;i<=mid;i++){
                prefix[queries[i][0]]+=queries[i][2];
                prefix[queries[i][1]+1]-=queries[i][2];
            }

            int flag = 0;
            for(int i=1;i<=n;i++){
                prefix[i]+=prefix[i-1];
                if(prefix[i-1]<nums[i-1]){
                    flag=1;
                    break;
                }
            }

            if(!flag){
                ans = mid+1;
                end=mid-1;
            } else {
                start=mid+1;
            }
        }
        return ans;
    }
};