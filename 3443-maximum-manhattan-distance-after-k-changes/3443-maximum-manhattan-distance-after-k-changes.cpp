class Solution {
public:
    int maxDistance(string s, int k) {
        vector<string> combinations = { "NE", "NW", "SE", "SW" };
        int ans = 0;
        for(int i=0;i<combinations.size();i++) {
            ans = max(ans,directionProcessing(combinations[i],s,k));
        }
        return ans;
    }

    int directionProcessing(string directions,string s,int k) {
        int ans = 0;
        int dist = 0;
        for(int i=0;i<s.length();i++) {
            if(directions[0]!=s[i] && directions[1]!=s[i]) {
                dist+=(k>0)?1:-1;
                k--;
            } else {
                dist++;
            }
            ans = max(dist,ans);
        }        
        return ans;
    }
};


/*

EWWE

00 -> 01 -> 

keep increasing j until it is possible

from a particular index i want a constant set of NW or NE or SW or SE


N   S   W   W   E   W

max Freq = W
freq of opposite (E) = 1

maxFreq = 1
Freq of opposite (S) = 1

N   N   W   W   W   W


N   W   S   E

W = 2
N = 1
S = 1

*/