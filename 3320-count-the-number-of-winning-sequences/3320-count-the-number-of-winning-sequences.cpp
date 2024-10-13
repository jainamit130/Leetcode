class Solution {
public:
    int mod = 1e9+7;
    vector<vector<unordered_map<char,int>>> cache;
    unordered_map<char,char> mp = { {'W','F'}, {'F','E'}, {'E','W'} };
    int n;
    int countWinningSequences(string s) {
        n = s.size();
        cache.resize(n + 1, vector<unordered_map<char,int>>(2 * n + 1));
        return solve(s, 0, 'S', 0) % mod;
    }

    int solve(string& s, int index, char last,int game) {
        if (index == n) {
            return game>=1;
        }

        if (game + n < 0 || game + n > 2 * n) return 0;

        if(cache[index][game+n].find(last)!=cache[index][game+n].end()){
            return cache[index][game+n][last];
        }

        int ans = 0;
        for (auto [p, r] : mp) {
            if (last != p) {
                ans += solve(s, index + 1, p, (r == s[index]) ? game + 1 : (p == s[index]) ? game : game - 1);
                ans %= mod; 
            }
        }

        return cache[index][game+n][last]=ans;
    }
};
