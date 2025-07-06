class Trie {
    public: 
        unordered_map<char,Trie*> children;
        int count;
        Trie() {
            count = 0;
        }

        void addWord(string& word,map<int,unordered_set<Trie*>>& mp,int k) {
            Trie* root = this;
            for(int i=0;i<word.length();i++) {
                char ch = word[i];
                if(root->children.find(ch)==root->children.end()) {
                    root->children[ch] = new Trie();
                }
                root=root->children[ch];
                root->count++;
                if(root->count>=k) {
                    mp[i+1].insert(root);
                }
            }
            return;
        }

        void removeWord(string& word,map<int,unordered_set<Trie*>>& mp,int k) {
            Trie* root = this;
            for(int i=0;i<word.length();i++) {
                char ch = word[i];
                root=root->children[ch];
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
        Trie* root = new Trie();
        map<int,unordered_set<Trie*>> mp;
        for(auto word:words) {
            root->addWord(word,mp,k);
        }

        vector<int> ans(words.size());
        for(int i=0;i<words.size();i++) {
            root->removeWord(words[i],mp,k);
            if(!mp.empty()) ans[i]=mp.rbegin()->first;
            root->addWord(words[i],mp,k);
        }
        return ans;
    }
};

/*
        l,k
jump -> 4,2
run ->  3,2

Ex:

jum
jump
jummer
run
runner

*/