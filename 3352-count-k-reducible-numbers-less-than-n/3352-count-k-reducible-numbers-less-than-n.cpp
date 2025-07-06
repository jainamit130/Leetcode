class Solution {
public:
    vector<int> isKReducible;
    vector<vector<vector<int>>> cache;
    int mod = 1e9+7;
    int countKReducibleNumbers(string s, int k) {
        isKReducible.resize(801);

        for (int i = 1; i < 801; i++) {
            int len = 0;
            int n = i;
            while (n > 1 && len < k) {
                int count = 0;
                int temp = n;
                while (temp > 0) {
                    if (temp & 1)
                        count++;
                    temp >>= 1;
                }
                n = count;
                len++;
            }
            isKReducible[i] = (len < k);
        }
        cache.resize(s.length()+1,vector<vector<int>>(s.length()+1,vector<int>(2,-1)));
        return solve(s, 0, 0, 1);
    }

    int solve(string& s, int index, int setBitsCount, int isPrefixMatch) {
        if (index == s.length()) {
            if (!isPrefixMatch && isKReducible[setBitsCount]) {
                return 1;
            }
            return 0;
        }

        if(cache[index][setBitsCount][isPrefixMatch]!=-1){
            return cache[index][setBitsCount][isPrefixMatch];
        }

        int ans = 0;
        if (isPrefixMatch) {
            if (s[index] == '1') {
                ans = (ans + solve(s, index + 1, setBitsCount + 1, true))%mod;
                ans = (ans + solve(s, index + 1, setBitsCount, false))%mod;
            } else {
                ans =(ans + solve(s, index + 1, setBitsCount, true))%mod;
            }
        } else {
            ans = (ans + solve(s, index + 1, setBitsCount + 1, false))%mod;
            ans = (ans + solve(s, index + 1, setBitsCount, false))%mod;
        }
        return cache[index][setBitsCount][isPrefixMatch]=ans;
    }
};

/*

1   1   0   1   0   1


1   1



*/