class Solution {
public:
    vector<vector<vector<int>>> cache;
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.length();
        cache.resize(k+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return solve(s,k,0,s.length()-1);
    }

    int solve(string& s,int k,int i,int j) {
        if(k<0) return INT_MIN;
        if(i>j) return 0;
        if(i==j) return 1;
        if(cache[k][i][j]!=-1) return cache[k][i][j];
        int ans = 1;
        int diff = abs(s[i]-s[j]);
        int oper = min(diff,26-diff);
        ans = max(ans,2+solve(s,k-oper,i+1,j-1));
        if(j-i+1>ans) ans = max(ans,solve(s,k,i+1,j));
        if(j-i+1>ans) ans = max(ans,solve(s,k,i,j-1));
        return cache[k][i][j]=ans;
    }
};


/*

States => ?
k,i,j


..... b .....
      i 
      j

a   b   c   d   e   f   g   h   j   k
    i
                                j


diff = abs(s[i]-s[j])
min(diff,26-diff);



*/