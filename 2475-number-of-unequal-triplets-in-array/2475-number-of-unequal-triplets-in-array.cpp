class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto n:nums) mp[n]++;
        int left = 0, right = nums.size();
        int ans = 0;
        for(auto [num,freq]:mp) {
            right-=freq;
            ans += left*freq*right;
            left+=freq;
        }
        return ans;
    }
};


// class Solution {
// public:
//     int unequalTriplets(vector<int>& nums) {
//         unordered_map<int,int> postMap;
//         unordered_map<int,int> preMap;
//         for(auto n:nums) {
//             postMap[n]++;
//         }
//         int n = nums.size();
//         int ans = 0;
//         for(int j=0;j<n;j++) {
//             postMap[nums[j]]--;
//             if(postMap[nums[j]]==0) postMap.erase(nums[j]);
//             int numberOfElementsAfter = n-j-1;
//             for(auto [num,freq]:preMap) {
//                 if(nums[j]==num) continue;
//                 ans += numberOfElementsAfter*freq;
//                 if(postMap.find(num)!=postMap.end()) ans -= postMap[num]*freq;
//                 if(postMap.find(nums[j])!=postMap.end()) ans -= postMap[nums[j]]*freq;
//             }
//             preMap[nums[j]]++;
//         }
//         return ans;
//     }
// };

/*

4   4   2   4   3
                i





*/