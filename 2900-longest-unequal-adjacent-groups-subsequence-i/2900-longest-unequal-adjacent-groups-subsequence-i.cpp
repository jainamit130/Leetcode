class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> word0;
        int last0 = 1;
        
        vector<string> word1;
        int last1 = 0;

        for(int i=0;i<words.size();i++) {
            string w0 = "";
            string w1 = "";

            if(groups[i]==0) {
                w0 += last0 ? words[i] : "";
                w1 += last1 ? words[i] : "";
            } else {
                w0 += last0 ? "" : words[i];
                w1 += last1 ? "" : words[i];
            }

            if(w0!="") {
                last0 = groups[i];
                word0.push_back(w0);
            }

            if(w1!="") {
                last1 = groups[i];
                word1.push_back(w1);
            }
        } 

        return word0.size()>word1.size() ? word0 : word1;
    }
};