class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> cache(s.length()+1,vector<int>(p.length()+1,-1));
        return dfs(0,0,s,p,cache);
    }

    bool dfs(int i,int j,string s,string p,vector<vector<int>>& cache){
        // cout<<i<<" "<<j<<endl;
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
            
        bool ans=false;
        if(p[j]=='*'){
            //skip
            ans=ans||dfs(i+1,j,s,p,cache);
            //take
            // ans=ans||dfs(i+1,j+1,s,p,cache);
            //empty
            ans=ans||dfs(i,j+1,s,p,cache);
        } else {
            ans=ans||dfs(i+1,j+1,s,p,cache);
        } 

        return cache[i][j]=ans;
    }
};




/*


a   c   d   c   b   b
                        j

a   *   c   ?   b
                i



* => 2 choices skip or take

*/