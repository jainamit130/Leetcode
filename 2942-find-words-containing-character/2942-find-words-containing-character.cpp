class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int i=0;
        vector<int> ans;
        for(auto word:words){
            for(auto ch:word){
                if(ch==x){
                    ans.push_back(i);
                    break;
                }
            }
            i++;
        } 
        return ans;
    }
};