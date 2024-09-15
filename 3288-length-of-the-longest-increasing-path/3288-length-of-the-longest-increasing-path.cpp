class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int n=coordinates.size();

        int a=coordinates[k][0];
        int b=coordinates[k][1];

        sort(coordinates.begin(),coordinates.end(),[](auto& lhs,auto& rhs){
            if(lhs[0]==rhs[0]){
                return lhs[1]>rhs[1];
            }
            return lhs[0]<rhs[0];
        });

        vector<int> leftLis;
        vector<int> rightLis;

        for(int i=0;i<n;i++){
            if(a==coordinates[i][0] || b==coordinates[i][1]) continue;

            if(coordinates[i][0]<a && coordinates[i][1]<b){
                updateLis(leftLis,coordinates[i][1]);
            }

            if(coordinates[i][0]>a && coordinates[i][1]>b){
                updateLis(rightLis,coordinates[i][1]);
            }
        }

        return leftLis.size()+1+rightLis.size();
    }

    void updateLis(vector<int>& lis,int val){
        auto it = lower_bound(lis.begin(),lis.end(),val);
        if(it==lis.end()){
            lis.push_back(val);
        } else {
            *it=val;
        }
        return;
    }
};