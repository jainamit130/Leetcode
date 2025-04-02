class Solution {
public:
    unordered_map<char,char> openEquivalentMp = {
        {'}','{'},
        {')','('},
        {']','['},
    };
    unordered_set<char> openBrackets = {'[','{','('};
    bool isValid(string s) {
        stack<char> st;
        for(auto ch:s) {
            if(openBrackets.find(ch)!=openBrackets.end()) st.push(ch);
            else {
                if(st.empty() || st.top()!=openEquivalentMp[ch]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};


/*
Clarifications

string is given ? yes
only brackets => {},[],()? yes 
if empty string return true ? yes


Approach
initializa a stack
start iterating the string s 
if open brackets encountered then push in the stack
if close brackets encountered then check top of stack if equivalent open bracket present then pop if not return false from there
if iteration completed then check if stack is empty or not

Time => O(n)
Space => O(n)
*/