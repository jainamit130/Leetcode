class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans="";
        for(int i=0;i<s.length();i++){
            ans+=s[(i+k)%s.length()];
        }
        return ans;
    }
};