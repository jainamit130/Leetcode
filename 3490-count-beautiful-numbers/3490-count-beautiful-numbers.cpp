class Solution {
public:
    unordered_map<string,int> cache;
    int beautifulNumbers(int l, int r) {
        int subAns1 = solve(to_string(l - 1), 0, 1, 0, 1, 1);
        cache.clear();
        int subAns2 = solve(to_string(r), 0, 1, 0, 1, 1);
        return subAns2-subAns1;
    }

    int solve(string numStr, int index, int prod, int sum, int isTight,int hasLeadingZero) {
        if (index >= numStr.size()) return (sum != 0 && prod % sum == 0);
        string key = to_string(index) + "-" + to_string(prod) + "-" + to_string(sum) + "-" + to_string(isTight) + "-" + to_string(hasLeadingZero);
        
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }
        int digitLimit = numStr[index] - '0';
        int upperBound = isTight ? digitLimit : 9;
        int ans = 0;
        for (int i = 0; i <= upperBound; i++) {
            if (i == 0) {
                ans += solve(numStr, index + 1, hasLeadingZero, sum, digitLimit == i && isTight, hasLeadingZero);
            } else {
                ans += solve(numStr, index + 1, prod * i, sum + i, digitLimit == i && isTight, 0);
            }
        }
        return cache[key]=ans;
    }
};

/*

5 7 1 = 13  35
5 7 2 = 14  70
5 7 3 = 15  105
5 7 4 = 16  140
5 7 5 = 17  175
5 7 6 = 18  210
5 7 7 = 19  245
5 7 8 = 20  280
5 7 9 = 21  315
5 8 0 = 22  400
5 8 1 = 23





7   8   2   4   9


_   _   _   _   _   _   _   _   _   _   _
0   1   2   3   4   5   6   7   8   9   10

*/