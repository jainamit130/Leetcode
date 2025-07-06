class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> countPair;
        for(string domain:cpdomains){
            int count=0;
            int i=0;
            while(domain[i]!=' '){
                count=count*10+(domain[i]-'0');
                i++;
            }
            i++;
            stack<string> st;
            string s="";
            for(;i<domain.length();i++){
                if(domain[i]=='.'){
                    st.push(s);
                    s="";
                } else 
                    s+=domain[i];
            }
            st.push(s);
            string prev="";
            while(!st.empty()){
                string str=st.top();
                st.pop();
                s=str;
                if(prev!="")
                    s+='.';
                s+=prev;
                countPair[s]+=count;
                prev=s;
            }
        }
        vector<string> ans;
        for(auto [str,c]:countPair){
            string s=to_string(c);
            s=s+" "+str;
            ans.push_back(s);
        }
        return ans;
    }
};