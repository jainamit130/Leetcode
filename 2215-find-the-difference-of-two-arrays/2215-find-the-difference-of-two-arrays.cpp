class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());
        unordered_set<int> visited;
        vector<vector<int>> ans(2);
        for(auto n:nums1){
            if(s2.find(n)==s2.end() && visited.find(n)==visited.end()){
                ans[0].push_back(n);
                visited.insert(n);
            }
        }
        visited.clear();
        for(auto n:nums2){
            if(s1.find(n)==s1.end() && visited.find(n)==visited.end()) {   
                ans[1].push_back(n);
                visited.insert(n);
            }
        }
        return ans;
    }
};