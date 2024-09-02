class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st;
        for(int i=0;i<words.size();i++){
            st.insert(words[i]);
        }
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            unordered_map<string,vector<int>> cache;
            if(solve(words[i],st,"",0,cache)){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }

    bool solve(string& word,unordered_set<string>& st,string curr,int index,unordered_map<string,vector<int>>& cache){
        if(index>=word.length()){
            return curr!=word && st.find(curr)!=st.end();
        }

        if(cache.find(curr)==cache.end()){
            cache[curr].resize(word.length()+1,-1);
        }
        
        if(cache[curr][index]!=-1){
            return cache[curr][index];
        }
        
        bool ans=false;
        ans=ans||solve(word,st,curr+word[index],index+1,cache);
        if(st.find(curr)!=st.end()){
            ans=ans||solve(word,st,"",index,cache);
        }
        return cache[curr][index]=ans;
    }
};


/*








*/