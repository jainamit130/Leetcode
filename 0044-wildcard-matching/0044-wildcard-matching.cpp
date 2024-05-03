class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> cache(s.length()+1,vector<int>(p.length()+1,-1));
        return dfs(0,0,s,p,cache);
    }

    bool dfs(int i,int j,string s,string p,vector<vector<int>>& cache){
        if(i>=s.length() && j>=p.length())
            return true;

        if(i<s.length() && j>=p.length())
            return false;

        if(i>=s.length()){
            while(j<p.length() && p[j]=='*'){
                j++;
            }
            return j>=p.length();
        }

        if(p[j]!='*' && p[j]!='?' && s[i]!=p[j]){
            return false;
        }

        if(cache[i][j]!=-1)
            return cache[i][j];

        cache[i][j]=0;
        if(p[j]=='*'){
            cache[i][j]=dfs(i,j+1,s,p,cache)||dfs(i+1,j,s,p,cache);
        } else {
            cache[i][j]=cache[i][j]||dfs(i+1,j+1,s,p,cache);
        } 

        return cache[i][j];
    }
};




/*


a   c   d   c   b   b
                        j

a   *   c   ?   b
                i



* => 2 choices skip or take

*/