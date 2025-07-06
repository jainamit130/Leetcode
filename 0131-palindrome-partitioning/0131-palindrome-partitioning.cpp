class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> current;
        dfs(s,0,current);
        return ans;
    }

    void dfs(string s,int index,vector<string>& current){
        if(index>=s.length()){
            ans.push_back(current);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(s,index,i))
            {current.push_back(s.substr(index,i-index+1));
            dfs(s,i+1,current);
            current.pop_back();}
        }
    }

    bool isPalindrome(string s,int index,int k){
        int i=index,j=k;
        if(i==j)
            return true;
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            } else 
                return false;
        }
        return true;
    }
};