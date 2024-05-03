// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         vector<vector<int>> cache(s.length()+1,vector<int>(p.length()+1,-1));
//         return dfs(0,0,s,p,cache);
//     }

//     bool dfs(int i,int j,string s,string p,vector<vector<int>>& cache){
//         // cout<<i<<" "<<j<<endl;
//         if(i>=s.length() && j>=p.length())
//             return true;

//         if(i<s.length() && j>=p.length())
//             return false;

//         if(i>=s.length()){
//             while(j<p.length() && p[j]=='*'){
//                 j++;
//             }
//             return j>=p.length();
//         }

//         if(p[j]!='*' && p[j]!='?' && s[i]!=p[j]){
//             return false;
//         }

//         if(cache[i][j]!=-1)
//             return cache[i][j];

//         bool ans=false;
//         if(p[j]=='*'){
//             //skip
//             ans=ans||dfs(i+1,j,s,p,cache);
//             //take
//             ans=ans||dfs(i,j+1,s,p,cache);
//         } else {
//             ans=ans||dfs(i+1,j+1,s,p,cache);
//         } 

//         return cache[i][j]=ans;
//     }
// };

class Solution {
public:

bool solve(string& str,string& pattern , int i , int j, vector<vector<int>>&dp)
{
    if(i<0 && j<0)
    {
        return true;
    }
    if(i>=0 && j<0)
    {
        return false;
    }
    if(j>=0 && i<0)
    {
        for(int k =0;k<=j;k++)
        {
            if(pattern[k]!='*')
            {
                return false;
            }
        }
        return true;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(pattern[j]=='?' || pattern[j]==str[i])
    {
        return dp[i][j]=solve(str,pattern, i-1,j-1,dp);
    }
    else if(pattern[j]=='*')
    {
       return dp[i][j]=solve(str,pattern, i-1,j,dp) || solve(str,pattern, i,j-1,dp);
    }
    else
    {
        return false;
    }
}
    bool isMatch(string s, string p)
    {
        vector<vector<int>>dp(s.length(),vector<int>(p.length(),-1));
        return solve(s,p,s.length()-1,p.length()-1,dp);
    }
};




/*


a   c   d   c   b   b
                        j

a   *   c   ?   b
                i



* => 2 choices skip or take

*/