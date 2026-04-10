class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> curr = {0,0,0};
        for(int i=0;i<triplets.size();i++) {
            vector<int> newCurr = {max(triplets[i][0],curr[0]),max(triplets[i][1],curr[1]),max(triplets[i][2],curr[2])};
            int flag = 0;
            for(int j=0;j<3;j++) {
                if(newCurr[j]>target[j]) {
                    flag = 1;
                    break;        
                }
            }
            if(!flag) curr = newCurr;
        }
        return target[0]==curr[0] && target[1]==curr[1] && target[2]==curr[2];
    }
};