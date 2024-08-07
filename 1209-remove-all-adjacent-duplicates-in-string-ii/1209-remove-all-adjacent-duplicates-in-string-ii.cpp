class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int i=0;
        while(i<s.length()){
            int count=1;
            while(i+1<s.length() && s[i]==s[i+1]){
                i++;
                count++;
            }
            if(count>=k){
                count-=k;
            }
            if(!st.empty() && st.top().first==s[i]){
                st.top().second+=count;
                if(st.top().second>=k){
                    st.top().second-=k;
                } 
                if(st.top().second==0){
                    st.pop();
                }
            } else if(count>0){
                st.push({s[i],count});
            }
            i++;
        }
        string ans;
        while(!st.empty()){
            int count=st.top().second;
            int ch=st.top().first;
            st.pop();
            for(int t=1;t<=count;t++){
                ans+=ch;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

/*

d   e   e   e   d   b   b   c   c   c   b   d   a   a
d1  e3  d1  b2  c3  b1  d1  a2       
                                i

stack: a2


*/