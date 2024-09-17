class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp1;
        string word="";
        for(int i=0;i<=s1.length();i++){
            if(i==s1.length() || s1[i]==' '){
                mp1[word]++;
                word="";
            } else {
                word+=s1[i];
            }
        }
        word="";
        vector<string> ans;
        for(int i=0;i<=s2.length();i++){
            if(i==s2.length() || s2[i]==' '){
                mp2[word]++;
                word="";
            } else {
                word+=s2[i];
            }
        }

        for(auto [w,c]:mp1){
            if(c==1 && mp2.find(w)==mp2.end()){
                ans.push_back(w);
            }
        }

        for(auto [w,c]:mp2){
            if(c==1 && mp1.find(w)==mp1.end()){
                ans.push_back(w);
            }
        }
        return ans;
    }
};