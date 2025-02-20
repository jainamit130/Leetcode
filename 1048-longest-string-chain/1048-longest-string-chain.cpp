class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](auto lhs,auto rhs) {
            return lhs.length()<rhs.length();
        });
        unordered_map<int,unordered_set<string>> mp;
        queue<pair<int,string>> q;
        unordered_map<string,int> maxCountMp;
        for(auto word:words) {
            q.push({1,word});
            maxCountMp[word]=1;
            mp[word.length()].insert(word);
        }

        int ans = 0;
        while(!q.empty()) {
            auto [count,word] = q.front();
            q.pop();
            ans = max(ans,count);
                for(int i=0;i<word.length();i++) {
                    string newWord = word;
                    newWord.erase(newWord.begin()+i);
                    if(mp[newWord.length()].find(newWord)!=mp[newWord.length()].end() && maxCountMp[newWord]<count+1) {
                        maxCountMp[newWord]=count+1;
                        q.push({count+1,newWord});
                    }
                }
        }
        return ans;
    }
};


/*


a   b   ba  bca bda bdca





*/