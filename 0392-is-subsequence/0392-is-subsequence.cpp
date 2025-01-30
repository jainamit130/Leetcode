class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0)
            return true;
        for(int i=t.length()-1;i>=0;i--){
            if(t[i]==s[s.length()-1]){
                s.pop_back();
            }
            if(s.length()==0)
                return true;
        }
        return false;
    }
};