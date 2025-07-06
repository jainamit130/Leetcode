class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> alpha(n+1);
        for(int i=0;i<shifts.size();i++) {
            int inc = shifts[i][2]?1:-1;
            alpha[shifts[i][0]]+=inc;
            alpha[shifts[i][1]+1]-=inc;
        }

        int runningShift = 0;
        string ans="";
        for(int i=0;i<n;i++) {
            runningShift+=alpha[i];
            int shift = runningShift%26;
            if (shift < 0) {
                shift += 26; 
            }
            ans.push_back('a' + (s[i] - 'a' + shift) % 26);
        }
        return ans;
    }
};