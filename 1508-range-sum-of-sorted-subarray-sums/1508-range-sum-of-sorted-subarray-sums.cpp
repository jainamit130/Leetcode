class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod=1e9+7;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        int count=0;
        int ans=0;
        while(count<right){
            int n=pq.top()[0];
            int i=pq.top()[1];
            pq.pop();
            if(left-1<=count){
                ans=(ans+n)%mod;
            }
            count++;
            if(i+1<nums.size())
                pq.push({n+nums[i+1],i+1});
        }
        return ans;
    }
};

//  1   2   6   7   8

/*
sum= 3

heap: 8   7   6

*/

// class Solution {
// public:
//     int rangeSum(vector<int>& nums, int n, int left, int right) {
//         vector<int> pq;
//         int mod=1e9+7;
//         for(int i=0;i<nums.size();i++){
//             int sum=0;
//             for(int j=i;j<nums.size();j++){
//                 sum+=nums[j];
//                 pq.push_back(sum);
//             }
//         }   
//         sort(pq.begin(),pq.end());
//         int ans=0;
//         for (int i=left-1;i<=right-1;i++){
//             ans=(long long)ans%mod+(long long)pq[i]%mod;
//         }
//         return ans;
//     }
// };