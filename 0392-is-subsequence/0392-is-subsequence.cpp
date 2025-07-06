class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0)
            return true;
        for(int i=t.length()-1;i>=0 && s.length()>0;i--){
            if(t[i]==s.back()){
                s.pop_back();
            }
        }
        return s.length()==0;
    }
};