class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict;
        for(auto d:dictionary){
            dict.insert(d);
        }
        string word="";
        string ans="";
        int flag=0;
        int i=0;
        while(i<sentence.length()) {
            if(sentence[i]==' '){
                if(!flag){
                    ans+=word;
                }
                ans+=" ";
                word="";
                flag=0;
                i++;
            } else {
                word+=sentence[i];
                i++;
            }
            if(dict.find(word)!=dict.end()){
                ans+=word;
                flag=1;
                while(i<sentence.length() && sentence[i]!=' '){
                    i++;
                }
            }
        }
        if(!flag){
            ans+=word;
        }
        return ans;
    }
};