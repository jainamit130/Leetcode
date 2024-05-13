class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        vector<vector<int>> freq(26,vector<int>(s.length()+1));
        for(int i=1;i<=s.length();i++){
            for(int j=0;j<26;j++){
                freq[j][i]=freq[j][i-1];
            }
            freq[s[i-1]-'a'][i]+=1;
        }
        vector<int> dp(s.length()+1,-1);
        return solve(dp,dp.size()-1,freq,s);
    }

    int solve(vector<int>& dp,int i,vector<vector<int>>& freq,string& s){
        if(i==-1){
            return 0;
        }

        if(dp[i]!=-1)
            return dp[i];

        int ans=s.length();
        for(int j=i;j>=0;j--){
            if(!goodArray(i,j,freq))
                continue;
            ans=min(ans,1+solve(dp,j-1,freq,s));
        }
        return dp[i]=ans;
    }

    bool goodArray(int i,int j,vector<vector<int>>& freq){
        int t=-1;
        for(int k=0;k<26;k++){
            int count=freq[k][i]-(j-1<0?0:freq[k][j-1]);
            if(count==0)
                continue;
            else {
                if(t==-1)
                    t=count;
                else if(t!=count)
                    return false; 
            }
        }
        return true;
    }
};


/*
            i
a : 0 1 1 2 2 3 3 4 4 4 4 4 4 
b : 0 0 1 1 2 2 3 3 3 3 3 3 4 
c : 0 0 0 0 0 0 0 0 1 2 2 2 2 
d : 0 0 0 0 0 0 0 0 0 0 1 2 2



*/