class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int totalA = 0;
        vector<int> prefix(n+1);
        for(int i=0;i<s.length();i++) {
            prefix[i+1] = prefix[i] + (s[i]=='a');
            totalA+=(s[i]=='a');
        }
        int ans = totalA;
        for(int i=0;i<n;i++) {
            int leftB = i - prefix[i];
            int rightA = totalA - prefix[i];
            ans = min(leftB + rightA, ans);
        }
        ans = min(ans,n-totalA);
        return ans;
    }
};


/*


    b   b   a   a   a   a   a   b   b
0   1   2   2   2   2   2   2   3   4
    5   5   5   4   3   2   1   0   0   0

    5   6   7   6   5   4   3   2   3   

*/