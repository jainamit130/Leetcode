class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> charCount1;
        for(auto word:words2) {
            for(auto ch:word) {
                charCount1[ch]++;
            }
        }
        vector<string> ans;
        for(auto word:words1) {
            unordered_map<char,int> charCount2;
            for(auto ch:word) {
                charCount2[ch]++;
            }

            int flag = 0;
            for(auto [ch,count]:charCount1) {
                if(charCount2.find(ch)==charCount2.end() || charCount1[ch]>charCount2[ch]) {
                    flag=1;
                    break;
                }
            }

            if(flag==0) ans.push_back(word);
        }
        return ans;
    }
};