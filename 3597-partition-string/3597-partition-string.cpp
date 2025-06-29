class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> st;
        vector<string> ans;
        string seg = "";
        for(int i=0;i<s.length();i++) {
            if(st.find(seg)==st.end()) {
                if(seg!="") {
                    st.insert(seg);
                    ans.push_back(seg);
                } 
                seg=s[i];
            } else {
                seg +=s[i];
            }
        }

        if(st.find(seg)==st.end()) ans.push_back(seg);
        return ans;
    }
};