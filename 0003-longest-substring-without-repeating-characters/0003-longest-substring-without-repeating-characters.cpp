class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        unordered_map<char,int> lastPos;
        int i=0;
        int ans = 1;
        lastPos[s[i]]=i;
        for(int j=1;j<s.length();j++){
            if(lastPos.find(s[j])!=lastPos.end()){
                while(i<=lastPos[s[j]]){
                    lastPos.erase(s[i]);
                    i++;
                }
            } 
            lastPos[s[j]]=j;
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};