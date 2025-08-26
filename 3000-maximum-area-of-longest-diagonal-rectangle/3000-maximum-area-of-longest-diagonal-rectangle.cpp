class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=0;
        double diagonal=0;
        for(int i=0;i<dimensions.size();i++){
            double d=sqrt(dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1]);
            if(diagonal<d){
                ans=dimensions[i][0]*dimensions[i][1];     
                diagonal=d;
            } else if(diagonal==d){
                ans=max(ans,dimensions[i][0]*dimensions[i][1]);
            }
        }
                
        return ans;
    }
};