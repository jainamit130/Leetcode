class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n%2!=0) return false;
        int lockedOpen = 0;
        int unlocked = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i]==')' && locked[i]=='1') {
                if(lockedOpen) {
                    lockedOpen--;
                } else if(unlocked){
                    unlocked--;
                } else {
                    return false;
                }
            } else if(locked[i]=='0'){
                unlocked++;
            } else {
                lockedOpen++;
            }
        }
        int lockedClose = 0;
        unlocked = 0;
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='(' && locked[i]=='1') {
                if(lockedClose) {
                    lockedClose--;
                } else if(unlocked){
                    unlocked--;
                } else {
                    return false;
                }
            } else if(locked[i]=='0'){
                unlocked++;
            } else {
                lockedClose++;
            }
        }
        return true;
    }
};