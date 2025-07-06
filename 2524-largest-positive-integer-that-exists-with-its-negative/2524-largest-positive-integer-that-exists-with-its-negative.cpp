class Solution {
public:
    int findMaxK(vector<int>& nums) {
        if(nums.size()==1)
            return -1;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<j && j<nums.size()){
            if(nums[i]>0 || nums[j]<0)
                return -1;
            int temp=abs(nums[i]);
            if(temp==nums[j]){
                return temp;
            } 
            if(temp<nums[j])
                j--;
            else {
                i++;
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int findMaxK(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         int ans=INT_MIN;
//         for(auto n:nums){
//             if(mp.find(-n)!=mp.end())
//                 ans=max(ans,abs(n));
//             mp[n]++;
//         }
//         if(ans==INT_MIN)
//             return -1;
//         return ans;
//     }
// };