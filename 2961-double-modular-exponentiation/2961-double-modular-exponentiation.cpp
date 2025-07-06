class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for(int i=0;i<variables.size();i++){
            int a=variables[i][0];
            int b=variables[i][1];
            int c=variables[i][2];
            int m=variables[i][3];
            int result=1;
            while(b>0){
                result=(result*a)%10;
                b--;
            }
            int finalResult=1;
            while(c>0){
                finalResult=(finalResult*result)%m;
                c--;
            }
            if(finalResult==target)
                ans.push_back(i);
        }
        return ans;
    }
};