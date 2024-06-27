class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char,int>> charFreq;
        calcFreq(s,charFreq);
        int ans=0;
        for(auto w:words){
            vector<pair<char,int>> wordFreq;
            calcFreq(w,wordFreq);
            int flag=0;
            if(wordFreq.size()!=charFreq.size()){
                flag=1;
                break;
            } else {
                for(int i=0;i<charFreq.size();i++){
                    if(charFreq[i].first==wordFreq[i].first){
                        if((charFreq[i].second<3 && charFreq[i].second==wordFreq[i].second) || (charFreq[i].second>=3 && wordFreq[i].second<=charFreq[i].second)) {
                            continue;
                        }
                    } 
                    flag=1;
                    break;
                }
                if(!flag)
                    ans++;
            }
        }
        return ans;
    }

    void calcFreq(string s,vector<pair<char,int>>& charFreq){
        char curr=s[0];
        int freq=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                freq++;
            } else {
                charFreq.push_back({curr,freq});
                freq=1;
                curr=s[i];
            }
        }
        charFreq.push_back({curr,freq}); 
    }
};