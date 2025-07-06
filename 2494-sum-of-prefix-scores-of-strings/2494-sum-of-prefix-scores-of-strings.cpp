class Trie {
    public:
        vector<Trie*> children;
        int count;
        Trie(){
            children.resize(26,NULL);
            count=0;
        }

        void construct(Trie* root,string& word){
            for(auto ch:word){
                if(root->children[ch-'a']==NULL){
                    root->children[ch-'a']=new Trie();
                }
                root=root->children[ch-'a'];
                root->count++;
            }
            return;
        }

        int dfs(Trie* root,string& word){
            int prefixCount=0;
            for(auto ch:word) {
                if(root->children[ch-'a']==NULL){
                    return prefixCount;
                }
                root=root->children[ch-'a'];
                prefixCount+=root->count;
            }
            return prefixCount;
        }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* root=new Trie();
        for(int i=0;i<words.size();i++){
            root->construct(root,words[i]);
        }

        vector<int> ans;
        for(int i=0;i<words.size();i++){
            ans.push_back(root->dfs(root,words[i]));
        }
        return ans;
    }
};