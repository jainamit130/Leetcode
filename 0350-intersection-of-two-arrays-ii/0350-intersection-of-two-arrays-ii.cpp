class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> ans;
        int last=1;
        for(int i=0;i<nums2.size();i++){
            if(i+1!=nums2.size() && nums2[i]==nums2[i+1]){
                last++;
                continue;
            } else {
                int elementLowerIndex=lower_bound(nums1.begin(),nums1.end(),nums2[i])-nums1.begin();
                if(elementLowerIndex>=0 && elementLowerIndex<nums1.size() && nums1[elementLowerIndex]==nums2[i]){
                    int elementNextGreaterIndex=upper_bound(nums1.begin(),nums1.end(),nums2[i])-nums1.begin();
                    int freq=min(elementNextGreaterIndex-elementLowerIndex,last);
                    for(int j=1;j<=freq;j++){
                        ans.push_back(nums2[i]);
                    }
                } 
                last=1;
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> mp1(1001);
//         vector<int> mp2(1001);
//         for(int i=0;i<nums1.size();i++){
//             mp1[nums1[i]]++;
//         }
//         for(int i=0;i<nums2.size();i++){
//             mp2[nums2[i]]++;
//         }
//         vector<int> ans;
//         for(int i=0;i<=1000;i++){
//             int freq=min(mp1[i],mp2[i]);
//             for(int j=1;j<=freq;j++){
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };