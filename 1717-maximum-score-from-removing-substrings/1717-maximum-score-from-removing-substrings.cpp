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
        int ans=0;
        stack<char> st2;
        ans+=process(st,st2,0,impStr,imp);
        stack<char> st3;
        ans+=process(st2,st3,1,nimpStr,nimp);
        return ans;
    }

    int process(stack<char>& st1,stack<char>& st2,int flag,string str,int score) {
        int ans=0;
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
            while(!st1.empty() && !st2.empty()){
                char secondChar=st2.top();
                char firstChar=st1.top();
                if(flag){
                    secondChar=st1.top();
                    firstChar=st2.top();
                }
                string word(1, firstChar);
                word += secondChar;
                if(word==str){
                    ans+=score;
                    st2.pop();
                    st1.pop();
                } else{
                    st2.push(st1.top());
                    st1.pop();
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