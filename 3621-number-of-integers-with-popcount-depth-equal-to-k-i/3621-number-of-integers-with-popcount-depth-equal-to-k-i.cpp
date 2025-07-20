class Solution {
public:
    long long dp[50][2][50];
    string toBinaryStr(long long n) {
        string s = "";
        while(n) {
            s += to_string(n&1);
            n=n>>1;
        }
        reverse(s.begin(),s.end());
        return s;
    }

    long long popcountDepth(long long n, int k) {
        if(k==0) return 1;
        unordered_set<int> validOneCounts;
        for(int i=1;i<50;i++) {
            int c = i, depth = 0;
            while(c>1) {
                c = __builtin_popcount(c);
                depth++;
            }
            if(depth==k-1) validOneCounts.insert(i);
        }
        if(validOneCounts.empty()) return 0;
        memset(dp,-1,sizeof(dp));
        long long ans = solve(toBinaryStr(n),validOneCounts,0,1,0);
        return ans - (k==1 && validOneCounts.count(1));
    }

    long long solve(string n,unordered_set<int>& validOnes,int pos,int isTight,int ones) {
        if(pos == n.length()) return validOnes.find(ones)!=validOnes.end();
        if(dp[pos][isTight][ones]!=-1) return dp[pos][isTight][ones];
        int limit = isTight ? n[pos]-'0' : 1;
        long long ans = 0;
        for(int i = 0; i<=limit; i++) {
            ans += solve(n,validOnes,pos+1,isTight & (i==limit),ones + i);
        }
        return dp[pos][isTight][ones]=ans;
    }
};