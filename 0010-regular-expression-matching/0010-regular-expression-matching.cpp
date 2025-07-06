class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> cache(s.length()+1,vector<int>(p.length()+1,-1));
        return dp(0,0,s,p,cache);
    }

    bool dp(int i,int j,string s,string p,vector<vector<int>>& cache){
        if(cache[i][j]!=-1)
            return cache[i][j];

        if(i>=s.length() && j>=p.length())
            return true;

        if(j>=p.length())
            return false;

        bool match=(i<s.length()) && (s[i]==p[j] || p[j]=='.');
        if(j+1<p.length() && p[j+1]=='*'){
            cache[i][j]= (match && dp(i+1,j,s,p,cache)) || dp(i,j+2,s,p,cache);
            return cache[i][j];
        } 
        if(match){
            cache[i][j]=dp(i+1,j+1,s,p,cache);
            return cache[i][j];
        } 
        cache[i][j]=false;
        return cache[i][j];
    }
};