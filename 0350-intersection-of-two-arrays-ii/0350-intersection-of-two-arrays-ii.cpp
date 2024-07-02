class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mp1(1001);
        vector<int> mp2(1001);
        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            mp2[nums2[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<=1000;i++){
            int freq=min(mp1[i],mp2[i]);
            for(int j=1;j<=freq;j++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};