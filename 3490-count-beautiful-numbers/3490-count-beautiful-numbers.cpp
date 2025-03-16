class Solution {
public:
    unordered_map<int,int> cache[100][10][2][2];
    void clean(){
        for(int i=0; i<10; i++){
            for(int sum=0; sum<100; sum++){
                cache[sum][i][0][0] = {};
                cache[sum][i][0][1] = {};
                cache[sum][i][1][0] = {};
                cache[sum][i][1][1] = {};
            }
        }
    }

    int beautifulNumbers(int l, int r) {
        string n1Str = to_string(l - 1);
        string n2Str = to_string(r);
        int subAns1 = solve(n2Str, 0, 1, 0, 1, 1);
        clean();
        int subAns2 = solve(n1Str, 0, 1, 0, 1, 1);
        return subAns1 - subAns2;
    }

    int solve(string numStr, int index, int prod, int sum, int isTight,int hasLeadingZero) {
        if (index >= numStr.size()) return (sum != 0 && prod % sum == 0);
        if(cache[sum][index][isTight][hasLeadingZero].find(prod)!=cache[sum][index][isTight][hasLeadingZero].end()) {
            return cache[sum][index][isTight][hasLeadingZero][prod];
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
        return cache[sum][index][isTight][hasLeadingZero][prod]=ans;
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