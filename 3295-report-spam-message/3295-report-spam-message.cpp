class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> st(bannedWords.begin(),bannedWords.end());
        int count=0;
        for(auto s:message){
            if(st.find(s)!=st.end()){
                count++;
            }
            if(count>1){
                return true;
            }
        }
        return false;
    }
};