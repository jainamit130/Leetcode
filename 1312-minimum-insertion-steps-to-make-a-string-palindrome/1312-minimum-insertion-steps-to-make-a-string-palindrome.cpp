class Solution {
public:
    vector<vector<int>> cache;
    int minInsertions(string s) {
        int n = s.length();
        cache.resize(n+1,vector<int>(n+1,-1));
        return solve(s,0,n-1);
    }

    int solve(string& s,int start,int end) {
        if(start>=end) return 0;
        if(cache[start][end]!=-1) return cache[start][end];
        int ans = s.length()-1;
        int lastIndex = end;
        // get lastIndex down to the point where s[lastIndex] == s[start]
        while(s[lastIndex]!=s[start]) lastIndex--;
        ans = min(end-lastIndex+solve(s,start+1,lastIndex-1),ans);
        ans = min(ans,1 + solve(s,start+1,end));
        return cache[start][end]=ans;
    }
};


/*






0   1   2   3   4   5   6   7   8
l   e   e   t   c   o   l   d   e
6   7   7   3   4   5   6   7   8
                    i
                        j

ans = j-lastOccurence or 1 + solve(i+1,j)

*/