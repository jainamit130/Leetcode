class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        solve({},nums,0);
        return ans;
    }

    void solve(vector<int> curr,vector<int>& nums,int index){
        if(index>=nums.size()){
            ans.push_back(curr);
            return;
        }

        solve(curr,nums,index+1);
        curr.push_back(nums[index]);
        solve(curr,nums,index+1);
        curr.pop_back();
        return;
    }
};