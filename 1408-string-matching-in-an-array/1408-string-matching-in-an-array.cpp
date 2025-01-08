class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(),words.end(),[](auto lhs,auto rhs) {
            return lhs.length()<rhs.length();
        });

        unordered_set<string> ansSt;
        for(int i=0;i<words.size()-1;i++) {
            string word1 = words[i];
            for(int j=i+1;j<words.size();j++) {
                string word2 = words[j];
                for(int k=0;k<=word2.length()-word1.length();k++) {
                    if(word1==word2.substr(k,word1.length())) {
                        ansSt.insert(word1);
                        break;
                    }
                }
            }
        }
        vector<string> ans(ansSt.begin(),ansSt.end());
        return ans;
    }
};


/*





*/