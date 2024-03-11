class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,pair<int,int>> mp;
        if(word1.length()!=word2.length())
            return false;
        for(int i=0;i<word1.length();i++)
            mp[word1[i]].first++;
 
        for(int i=0;i<word1.length();i++){
            if(mp.find(word2[i])!=mp.end())
                mp[word2[i]].second++;
            else return false;
        }   
        while(mp.size()){
            int currentSize=mp.size();
            pair<char,pair<int,int>> it={mp.begin()->first,mp.begin()->second};
            if(it.second.first==it.second.second){
                mp.erase(it.first);
                continue;
            } else {
                unordered_map<char,pair<int,int>>::iterator itr=mp.begin();
                itr++;
                while(itr!=mp.end()){
                    if(itr->second.second==it.second.first){
                        itr->second.second=it.second.second;
                        mp.erase(it.first);
                        break;
                    }
                    itr++;
                }
                if(currentSize==mp.size())
                    return false;
            }
        }
        return true;
    }
};