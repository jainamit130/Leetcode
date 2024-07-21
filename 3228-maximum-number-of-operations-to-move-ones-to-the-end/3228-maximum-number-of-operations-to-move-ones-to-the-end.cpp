class Solution {
public:
    int maxOperations(string s) {
        int streak=1;
        int currStreak=0;
        int ans=0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='1' && s[i+1]=='1'){
                streak++;
            }
            if(s[i]=='1' && s[i+1]=='0'){
                currStreak+=streak;
                streak=1;
            }
            if(s[i]=='0' && s[i+1]=='1'){
                ans+=currStreak;
            }
        }

        if(s.back()=='0'){
            ans+=currStreak;
        }
        return ans;
    }
};



/*

0   0 => do nothing
1   1 => streak++
1   0 => currStreak+=streak and initialize streak back to 1
0   1 => add currStreak to ans


1   0   1   0   1   1   1   0   1   0


0   0   1   1   1   1   1   0   1   0

0   0   0   1   1   1   1   1   1   0

0   0   0   0   1   1   1   1   1   1

1+5+6=12

*/