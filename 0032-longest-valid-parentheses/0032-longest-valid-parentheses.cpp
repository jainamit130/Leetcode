class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<int,char>> st;
        int i=0;
        int ans=0;
        while(i<s.length()){
            // printStack(st);
            if(s[i]==')'){
                if(!st.empty() && st.top().second=='('){
                    int openIndex=st.top().first;
                    st.pop();
                    int lastInvalid=-1;
                    if(!st.empty()){
                        lastInvalid=st.top().first;
                    }
                    ans=max(ans,i-lastInvalid);
                } else {
                    st.push({i,')'});
                }
            } else {
                st.push({i,'('});
            }
            i++;
        }
        return ans;
    }

    // void printStack(stack<pair<int,char>> st){
    //     while(!st.empty()){
    //         cout<<st.top().first<<","<<st.top().second<<" ";
    //         st.pop();
    //     }
    //     cout<<endl;
    //     return;
    // }
};

/*

Stack: 0)   5) 

ans=4

0   1   2   3   4   5   6   7
)   (   )   (   )   )   (   )
                            i


Stack: 0(

(   )
    i

                      




*/