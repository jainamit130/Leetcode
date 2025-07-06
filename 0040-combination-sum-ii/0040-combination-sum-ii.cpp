class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        combination(candidates,target,0,{});
        return ans;
    }

    void combination(vector<int>& candidates, int target,int index, vector<int> currentCombo){
        
        if(target==0){
            ans.push_back(currentCombo);
            return;
        }

        for(int i=index;i<candidates.size();i++){
            
            if(i > index && candidates[i] == candidates[i-1])
                continue;

            if(candidates[i]>target)
                break;

            currentCombo.push_back(candidates[i]);
            combination(candidates,target-candidates[i],i+1,currentCombo);
            currentCombo.pop_back();
        }
        return;
    }
};