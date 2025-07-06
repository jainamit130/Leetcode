class Solution {
public:
    using ll=long long;
    ll minCost(vector<int>& nums, vector<int>& cost) {
        vector<vector<int>> combined;
        for(int i=0;i<nums.size();i++){
            combined.push_back({nums[i],cost[i]});
        }
        sort(combined.begin(),combined.end());  
        int l=combined[0][0],r=combined.back()[0];
        ll ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            ll cost1=findCost(combined,mid);
            ll cost2=findCost(combined,mid+1);
            ans=min(cost1,cost2);
            if(cost1<=cost2){
                r=mid-1;
            } else {
                l=mid+1;
            }
        } 
        return ans;
    }

    ll findCost(vector<vector<int>>& combined,int target){
        ll ans=0;
        for(int i=0;i<combined.size();i++){
            ans+=(ll)abs(combined[i][0]-target)*(ll)combined[i][1];
        }
        return ans;
    }
};


// class Solution {
// public:
//     long long minCost(vector<int>& nums, vector<int>& cost) {
//         vector<vector<int>> combined;
//         for(int i=0;i<nums.size();i++){
//             combined.push_back({nums[i],cost[i]});
//         }
//         sort(combined.begin(),combined.end());
//         for(int i=0;i<combined.size();i++){
//             cout<<combined[i][0]<<" "<<combined[i][1]<<endl;
//         }
//         int i=0,j=nums.size()-1;
//         while(i<j){
//             long long diff=abs(combined[i][0]-combined[j][0]);
//             //Case1 i -> j i++
//             long long case1=(long long)diff*(long long)combined[i][1];
//             long long case2=(long long)diff*(long long)combined[j][1];
//             if(case1<case2){
//                 i++;
//             } else {
//                 j--;
//             }
//         }
//         long long ans=0;
//         for(int k=0;k<nums.size();k++){
//             int diff=abs(nums[k]-combined[i][0]);
//             cout<<diff<<endl;
//             ans+=(long long)diff*cost[k];
//         }
//         return ans;
//     }
// };