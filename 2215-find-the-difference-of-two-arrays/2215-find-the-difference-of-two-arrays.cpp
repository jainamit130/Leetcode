class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size();
        int m = nums2.size();
        vector<int> num1s;
        vector<int> num2s;
        int  i = 0, j = 0;
        while(i < n && j < m){
            if(nums1[i] == nums2[j]){
                while(i+1 < n  && nums1[i] == nums1[i+1]) i++;
                while(j+1 < m && nums2[j] == nums2[j+1]) j++;
                i++; j++;
            }else if(nums1[i] < nums2[j]){
                num1s.push_back(nums1[i]);
                while(i+1 < n && nums1[i] == nums1[i+1]) i++;
                i++;
            }else{
                num2s.push_back(nums2[j]);
                while(j+1 < m && nums2[j] == nums2[j+1]) j++;
                j++;
            }
        }
        while( i < n) {
            num1s.push_back(nums1[i]);
            while(i+1 < n && nums1[i] == nums1[i+1]) i++;
            i++;
        }
        while(j < m) {
            num2s.push_back(nums2[j]);
            while(j+1 < m && nums2[j] == nums2[j+1]) j++;
            j++;
        }
        return {num1s, num2s};
    }
};

// class Solution {
// public:
//     vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
//         unordered_set<int> s1(nums1.begin(),nums1.end());
//         unordered_set<int> s2(nums2.begin(),nums2.end());
//         unordered_set<int> visited;
//         vector<vector<int>> ans(2);
//         for(auto n:nums1){
//             if(s2.find(n)==s2.end() && visited.find(n)==visited.end()){
//                 ans[0].push_back(n);
//                 visited.insert(n);
//             }
//         }
//         visited.clear();
//         for(auto n:nums2){
//             if(s1.find(n)==s1.end() && visited.find(n)==visited.end()) {   
//                 ans[1].push_back(n);
//                 visited.insert(n);
//             }
//         }
//         return ans;
//     }
// };