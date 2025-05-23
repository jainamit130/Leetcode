class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int start=0;
        int end= queries.size()-1;
        int n = nums.size();
        int ans = -1;
        while(start<=end) {
            int mid = (start+end)/2;
            vector<int> prefix(n+1);
            for(int i=0;i<=mid;i++) {
                prefix[queries[i][0]]+=queries[i][2];
                prefix[queries[i][1]+1]-=queries[i][2];
            }

            int flag = 0;
            int flag1 = 0;
            for(int i=1;i<=n;i++){
                prefix[i]+=prefix[i-1];
                if(nums[i-1]!=0) {
                    flag1=1;
                }
                if(prefix[i-1]<nums[i-1]){
                    flag=1;
                    break;
                }
            }

            if(!flag) {
                ans = flag1?mid+1:mid;
                end = mid-1;
            } else {
                start = mid+1;
            }

        }
        return ans;
    }
};