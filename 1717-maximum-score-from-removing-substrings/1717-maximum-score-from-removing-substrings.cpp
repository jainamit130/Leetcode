class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans=0;
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]!='b' && s[i]!='a'){
                stack<char> copy=st;
                ans+=max(consumeStack(copy,x,y,"ab","ba"),consumeStack(st,y,x,"ba","ab"));
            } else {
                st.push(s[i]);
            }
        }
        stack<char> copy=st;
        ans+=max(consumeStack(copy,x,y,"ab","ba"),consumeStack(st,y,x,"ba","ab"));
        return ans;
    }

    int consumeStack(stack<char>& st,int imp,int nimp,string impStr,string nimpStr){
        stack<char> st2;
        int ans=0;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
            while(!st.empty() && !st2.empty()){
            char secondChar=st2.top();
            char firstChar=st.top();
            string word(1, firstChar);
            word += secondChar;
            if(word==impStr){
                ans+=imp;
                st2.pop();
                st.pop();
            } else{
                st2.push(st.top());
                st.pop();
            }
            }
        }
        stack<char> st3;
        while(!st2.empty()){
            st3.push(st2.top());
            st2.pop();
            while(!st2.empty() && !st3.empty()){
            char secondChar=st2.top();
            char firstChar=st3.top();
            string word(1, firstChar);
            word += secondChar;
            if(word==nimpStr){
                ans+=nimp;
                st3.pop();
                st2.pop();
            } else{
                st3.push(st2.top());
                st2.pop();
            }
            }
        }
        return ans;
    }
};



/*

c   d   b   c   b   b   a   a   a   b   a   b
                                            i
st: b   b   a   a   a      
point: 18

st2: b  

*/