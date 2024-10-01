class Solution {
public:
    vector<int> computeZ(string s) {
    int n = s.size();
    vector<int> Z(n);
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i <= R) {
            Z[i] = min(R - i + 1, Z[i - L]);
        }
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }
        if (i + Z[i] - 1 > R) {
            L = i;
            R = i + Z[i] - 1;
        }
    }
    return Z;
}

int minStartingIndex(string s, string p) {
    string concat = p + s;
    reverse(p.begin(),p.end());
    reverse(s.begin(),s.end());
    string reverseConcat = p + s;
    vector<int> Z = computeZ(concat);
    vector<int> Z1= computeZ(reverseConcat);
    int m = p.size();   
    int n = s.size(); 
    
    for (int i = 0; i <= n - m; ++i)
        if (Z[m + i] + 1 + Z1[n - i] >= m)
            return i;
    return -1;
}
};