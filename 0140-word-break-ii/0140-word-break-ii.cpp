class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for(auto word:wordDict)
            words.insert(word);
        
        return solve(0,words,s);
    }

    vector<string> solve(int start,unordered_set<string>& words,string& s){
        if(start==s.length())
            return {""};

        vector<string> ans;
        for(int end=start;end<s.length();end++){
            string word = s.substr(start,end-start+1);
            if(words.find(word)==words.end())
                continue;
            vector<string> strings = solve(end+1,words,s);
            if(strings.empty())
                continue; 
                
            string sentence;
            for(auto substr:strings){
                sentence=word;
                if(substr.length()!=0)
                    sentence+=" "+substr;
                ans.push_back(sentence);
            }
        }
        return ans;
    }
};


/*

pineapplepenapple
pine    apple   pen   apple

pineapplepenapple
pineapple pen apple

pineapplepenapple
pine applepen apple

*/