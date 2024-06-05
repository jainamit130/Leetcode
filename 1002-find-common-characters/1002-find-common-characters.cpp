class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26,INT_MAX);
        for(auto w:words){
            vector<int> freq1(26);
            for(int i=0;i<w.length();i++){
                freq1[w[i]-'a']++;
            }
            for(int j=0;j<26;j++){
                freq[j]=min(freq[j],freq1[j]);
            }
        }
        vector<string> ans;
        for(int i=0;i<26;i++){
            int c=freq[i];
            string ch(1,char(i+'a'));
            for(int j=1;j<=c;j++){
                ans.push_back(ch);
            }
        }
        return ans;
    }
};