class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[&](auto& lhs,auto& rhs){
            if(lhs[0]==rhs[0]){
                return lhs[1]>rhs[1];
            }
            return rhs[0]>lhs[0];
        });
        int ans=0;
        for(int i=0;i<points.size()-1;i++){
            for(int j=i+1;j<points.size();j++){
                int flag=1;
                if(points[i][1] >= points[j][1]){
                    for(int k=i+1;k<j;k++){
                        if(points[k][1]<=points[i][1] && points[k][1]>=points[j][1]){
                            flag=0;
                            break;
                        }
                    }
                    if(flag)
                        ans++;
                }
            }
        }
        return ans;
    }
};