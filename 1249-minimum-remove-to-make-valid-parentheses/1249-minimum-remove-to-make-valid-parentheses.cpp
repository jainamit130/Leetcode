//Approach1
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> indexesToDelete;
        stack<int> indexes;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                indexes.push(i);
            else if(s[i]==')'){
                if(indexes.empty()){
                    indexesToDelete.insert(i);
                } else {
                    indexes.pop();
                }
            }
        }
        while(!indexes.empty()){
            indexesToDelete.insert(indexes.top());
            indexes.pop();
        }
        string ans="";
        for(int i=0;i<s.length();i++){
            if(indexesToDelete.find(i)!=indexesToDelete.end()){
                continue;
            } else {
                ans+=s[i];
            }
        }
        return ans;
    }
};