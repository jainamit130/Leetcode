class Solution {
public:
    int mod = 1e9 + 7;

    int numWays(vector<string>& words, string target) {
        int n = words[0].length();
        int m = target.length();

        // Create a map to count occurrences of (position, character) in words
        vector<map<char, int>> mp(n);
        for (auto& word : words) {
            for (int j = 0; j < n; ++j) {
                mp[j][word[j]]++;
            }
        }

        // Memoization table
        vector<vector<int>> cache(n, vector<int>(m, -1));

        return solve(words, 0, 0, target, cache, mp);
    }

    int solve(vector<string>& words, int usableIndexes, int index, string& target,
              vector<vector<int>>& cache, vector<map<char, int>>& mp) {
        if (index >= target.size()) {
            return 1;
        }

        if (usableIndexes >= words[0].length()) {
            return 0;
        }

        if (cache[usableIndexes][index] != -1) {
            return cache[usableIndexes][index];
        }

        char ch = target[index];
        long long ans = 0;

        // Case 1: Do not pick character from words[usableIndexes]
        ans = (ans + solve(words, usableIndexes + 1, index, target, cache, mp)) % mod;

        // Case 2: Pick character ch from words[usableIndexes]
        if (mp[usableIndexes].count(ch) > 0) {
            ans = (ans + (long long) mp[usableIndexes][ch] * solve(words, usableIndexes + 1, index + 1, target, cache, mp)) % mod;
        }

        return cache[usableIndexes][index] = ans;
    }
};
/*

ch, i

if(character from string i matches then i can skip or take from any of the string)


    0   1   2   3
0   a   c   c   a
1   b   b   b   b
2   c   a   c   a

0   0   0
0   0   1
0   0   2
0   1   1
0   1   2
0   2   2
1   1   1
1   1   2
1   2   2
2   2   2

0   1   2
a   b   c

0   1   3


0   2   3

1   2   3


*/