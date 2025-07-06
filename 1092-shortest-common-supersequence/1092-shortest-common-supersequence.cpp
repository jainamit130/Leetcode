class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int str1Length = str1.length();
        int str2Length = str2.length();

        vector<vector<int>> dp(str1Length + 1, vector<int>(str2Length + 1, 0));

        for (int row = 0; row <= str1Length; row++) {
            dp[row][0] = row;
        }
        for (int col = 0; col <= str2Length; col++) {
            dp[0][col] = col;
        }

        for (int row = 1; row <= str1Length; row++) {
            for (int col = 1; col <= str2Length; col++) {
                if (str1[row - 1] == str2[col - 1]) {
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                } else {
                    dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + 1;
                }
            }
        }

        string supersequence = "";
        int row = str1Length, col = str2Length;

        while (row > 0 && col > 0) {
            if (str1[row - 1] == str2[col - 1]) {
                supersequence += str1[row - 1];
                row--;
                col--;
            } else if (dp[row - 1][col] < dp[row][col - 1]) {
                supersequence += str1[row - 1];
                row--;
            } else {
                supersequence += str2[col - 1];
                col--;
            }
        }

        while (row > 0) {
            supersequence += str1[row - 1];
            row--;
        }
        while (col > 0) {
            supersequence += str2[col - 1];
            col--;
        }

        reverse(supersequence.begin(), supersequence.end());
        return supersequence;
    }
};

// class Solution {
// public:
//     vector<vector<string>> cache;
//     string shortestCommonSupersequence(string str1, string str2) {
//         cache.resize(str1.length(),vector<string>(str2.length(),""));
//         return solve(str1,str2,0,0);
//     }

//     string solve(string& str1,string& str2,int i,int j) {
//         // base cases
//         if(i>=str1.length()) {
//             if(j>=str2.length()) {
//                 return "";
//             } else {
//                 return str2.substr(j);
//             }
//         } else if(j>=str2.length()) {
//             return str1.substr(i);
//         }

//         if(cache[i][j]!="") {
//             return cache[i][j];
//         }
//         string ans = str1+str2;
//         if(str1[i]==str2[j]) {
//             string subAns1 = str1[i] + solve(str1,str2,i+1,j+1);
//             if(subAns1.length() < ans.length()) ans = subAns1;
//         } else {
//             string subAns2 = str1[i] + solve(str1,str2,i+1,j);
//             if(subAns2.length() < ans.length()) ans = subAns2;
//             string subAns3 = str2[j] + solve(str1,str2,i,j+1);
//             if(subAns3.length() < ans.length()) ans = subAns3;
//         }

//         return cache[i][j]=ans;
//     }
// };


/*
a   b   a   c   
c   a   b



*/