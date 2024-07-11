class Solution {
public:
    bool isValid(string s) {
        stack<int> q;
        int c=0;
        map<char,char> mp={{'}','{'},{')','('},{']','['}};
        for(int i=0;i<s.length();i++){
            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                q.push(s[i]);
                c++;
            }
            else if(s[i]=='}' || s[i]==')' || s[i]==']'){
                c--;
                if(c<0)
                    return false;
                if(q.top()!=mp[s[i]])
                    return false;
                else{
                    q.pop();
                }
            }
        }
        if(c!=0)
            return false;
        return true;
    }
};