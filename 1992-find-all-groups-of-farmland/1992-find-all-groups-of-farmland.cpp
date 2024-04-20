class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[0].size();j++){
                if(land[i][j]==-1)
                    continue;
                if(land[i][j]==1){
                    vector<int> t;
                    t.push_back(i);
                    t.push_back(j);
                    int k=i+1;
                    int count1=0;
                    while(k<land.size() && land[k][j]==1){
                        count1++;
                        k++;
                    }
                    k=j+1;
                    int count2=0;
                    while(k<land[0].size() && land[i][k]==1){
                        count2++;
                        k++;
                    }
                    t.push_back(i+count1);
                    t.push_back(j+count2);
                    for(int m=i;m<=i+count1;m++){
                        for(int n=j;n<=j+count1;n++){
                            land[m][n]=-1;
                        }   
                    }
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};



/*

1   1   0   0   0   1
1   1   0   0   0   0



*/