class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currentVector;
        bt(nums,0,currentVector);
        return ans;
    }

    void bt(vector<int>& nums,int index,vector<int>& currentVector){

        ans.push_back(currentVector);

        for(int i=index;i<nums.size();i++){
            currentVector.push_back(nums[i]);
            bt(nums,i+1,currentVector);
            currentVector.pop_back();
        }
        return;
    }
};