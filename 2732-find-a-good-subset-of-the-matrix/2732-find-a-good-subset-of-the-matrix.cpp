class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        unordered_map<string,int> mp;

        for(int i=0;i<grid.size();i++) {
            
            string gStr = "";
            vector<int> initSum;
            bool isValid = true;
            for(auto n:grid[i]) {
                if(n==1){
                    isValid = false;
                }
                initSum.push_back(n);
                gStr += to_string(n);
            }

            if(isValid) {
                return {i};
            }
            int index = checkAllChoices(mp,initSum,"",0);
            if(index!=-1){
                return {index,i};
            }
            mp[gStr]=i;
        }
        return {};
    }

    int checkAllChoices(unordered_map<string,int>& mp,vector<int>& initSum,string generatedStr,int index) {
        if(index==initSum.size()) {
            if(mp.find(generatedStr)!=mp.end()) {
                return mp[generatedStr];
            } 
            return -1;
        }

        int ans = -1;
        if(initSum[index]==0) {
            ans = checkAllChoices(mp,initSum,generatedStr+"0",index+1);
            if(ans==-1) {
                ans = checkAllChoices(mp,initSum,generatedStr+"1",index+1);;
            }
        } else {
            ans = checkAllChoices(mp,initSum,generatedStr+"0",index+1);
        }

        return ans;
    }
};