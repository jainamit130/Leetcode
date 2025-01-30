class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.length()<s.length()) return false;
        if(t==s) return true; 
        vector<vector<int>> nextEarliestAlphaIndex(t.length()+1,vector<int>(26,-1));
        for(int i=t.length()-2;i>=0;i--) {
            nextEarliestAlphaIndex[i+1]=nextEarliestAlphaIndex[i+2];
            nextEarliestAlphaIndex[i+1][t[i+1]-'a']=i+2;
        }
        nextEarliestAlphaIndex[0]=nextEarliestAlphaIndex[1];
        nextEarliestAlphaIndex[0][t[0]-'a']=1;

        int hopIndex = 0;
        int i=0;
        while(i<s.length()) {
            int potentialNextHopIndex = nextEarliestAlphaIndex[hopIndex][s[i]-'a'];
            if(potentialNextHopIndex==-1) return false;
            hopIndex=potentialNextHopIndex;
            i++;
        }
        return true;
    }
};


/*

length of the string


*/