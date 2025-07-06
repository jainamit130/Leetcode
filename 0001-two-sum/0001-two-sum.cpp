class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> nums1;
        for(int i=0;i<nums.size();i++){
            nums1.push_back({nums[i],i});
        }
        sort(nums1.begin(),nums1.end());
        int i=0,j=nums1.size()-1;
        while(i<j){
            if(nums1[j].first>(target-nums1[i].first))
                j--;
            else if(nums1[j].first<(target-nums1[i].first))
                i++;
            else
                break;
        }
        return {nums1[i].second,nums1[j].second};
    }
};