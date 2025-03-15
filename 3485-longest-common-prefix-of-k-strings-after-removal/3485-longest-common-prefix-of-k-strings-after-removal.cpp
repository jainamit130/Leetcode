class Trie {
    public:
        unordered_map<char,Trie*> children;
        int count;
        Trie() {
            count = 0;
        }
        
        void addWord(Trie* root,string& word, map<int,unordered_set<Trie*>>& mp,int k){
            for(int i=0;i<word.length();i++){
                char ch = word[i];
                if(root->children.find(ch-'a')==root->children.end()){
                    root->children[ch-'a']=new Trie();
                }
                root=root->children[ch-'a'];
                root->count++;
                if(root->count>=k) {
                    mp[i+1].insert(root);
                }
            }
            return;
        } 

        void removeWord(Trie* root,string word,map<int,unordered_set<Trie*>>& mp,int k) {
            for(int i=0;i<word.length();i++){
                char ch = word[i];
                root=root->children[ch-'a'];
                root->count--;
                if(root->count+1==k) {
                    mp[i+1].erase(root);
                    if(mp[i+1].size()==0) {
                        mp.erase(i+1);
                    }
                }
            }
            return;
        }
};

class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        Trie* root=new Trie();
        map<int,unordered_set<Trie*>> mp;
        for(int i=0;i<words.size();i++){
            root->addWord(root,words[i],mp,k);
        }
        vector<int> ans(words.size());
        for(int i=0;i<words.size();i++){
            root->removeWord(root,words[i],mp,k);
            if(mp.empty()) {
                root->addWord(root,words[i],mp,k);
                continue;    
            }
            ans[i] = mp.rbegin()->first;

            root->addWord(root,words[i],mp,k);
        }
        return ans;
    }
};

/*


jump
run
run
jump
run

k=2




*/