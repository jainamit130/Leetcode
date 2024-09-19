class Solution {
public:
    vector<int> ans;
    vector<int> diffWaysToCompute(string expression) {
        solve(expression,0,index,0);
        return ans;
    }

    int solve(string expression,int count,int index,int result){
        if(count==expression.length()/2){
            ans.push_back(result);
            return;
        }

        
    }

};