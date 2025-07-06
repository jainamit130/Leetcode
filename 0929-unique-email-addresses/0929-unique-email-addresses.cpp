class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(auto email:emails){
            string compEmail = "";
            int i=0;
            for(;i<email.length();i++){
                char ch=email[i];
                if(ch=='.'){
                    continue;
                } else if(ch=='+' || ch=='@'){
                    break;
                } else {
                    compEmail+=ch;
                }
            }
            while(i<email.length() && email[i]!='@'){
                i++;
            }
            compEmail+=email.substr(i);
            st.insert(compEmail);
        }
        return st.size();
    }
};