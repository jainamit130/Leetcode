class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(s1.length()>0){
                    s1.pop_back();
                }
            } else {
                s1+=s[i];
            }
        }
        string s2="";
        for(int i=0;i<t.length();i++){
            if(t[i]=='#'){
                if(s2.length()>0){
                    s2.pop_back();
                }
            } else {
                s2+=t[i];
            }
        }
        return s1==s2;
    }
};