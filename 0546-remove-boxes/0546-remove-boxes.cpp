class Solution {
public:
    int dp[101][101][101];
    int func(int i, int j, int extra, vector<int> &num, vector<int> &grp){
        if(i>j) return 0;
        if(dp[i][j][extra]!=-1) return dp[i][j][extra];
        int maxi = (grp[i]+extra)*(grp[i]+extra)+func(i+1,j,0,num,grp);
        for(int ind = i+1; ind<=j; ind++){
            if(num[i]==num[ind]){
                maxi = max(maxi,func(i+1,ind-1,0,num,grp)+func(ind,j,extra+grp[i],num,grp));
            }
        } 
        return dp[i][j][extra] = maxi;
    }
    int removeBoxes(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        vector<int> num;
        vector<int> grp;
        while(i<n){
            int j = i;
            num.push_back(arr[i]);
            while(j<n && arr[i]==arr[j]) j++;
            grp.push_back(j-i);
            i = j;
        }

        memset(dp,-1,sizeof(dp));
        return func(0,grp.size()-1,0,num,grp);
    }
};