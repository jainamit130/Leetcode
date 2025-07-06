class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLen=words[0].length();
        if(s.length()<wordLen)
            return {};
        unordered_map<string,int> mp;
        for(auto word:words){
            mp[word]++;
        }
        unordered_map<string,int> mpCopy=mp;
        string currWord="";
        vector<int> ans;
        for(int k=0;k<s.length()-words.size()*wordLen+1;k++){
            mp=mpCopy;
            int i=k,j=k;
            while(j<s.length()){
                currWord=s.substr(j,wordLen);
                if(mp.find(currWord)!=mp.end()){
                    mp[currWord]--;
                    if(mp[currWord]==0)
                        mp.erase(currWord);
                    j+=wordLen;
                } else {
                    break;
                }
                if(mp.size()==0){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};


/*

lingmindraboofooowingdingbarrwingmonkeypoundcake


*/