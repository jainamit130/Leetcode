class TrieNode{
    public:
        map<char,TrieNode*> children;
        bool end;
        TrieNode(){end=false;}
};

class Trie{
    public:
        TrieNode* root;
        Trie(){
            root=new TrieNode();
        }
        void insert(string s){
            TrieNode* current=root;
            for(auto ch:s){
                if(current->children.find(ch)==current->children.end())
                    current->children[ch]=new TrieNode();
                current=current->children[ch];
            }
            current->end=true;
        }
};

class Solution {
public:
    vector<int> ans;
    vector<int> lexicalOrder(int n) {
        Trie* data = new Trie();
        for(int i=1;i<=n;i++){
            data->insert(to_string(i));
        }
        dfs(data->root,0);
        return ans;
    }

    void dfs(TrieNode* root,int current){     
        if(root->end)
            ans.push_back(current);

        for(char ch = '0';ch <='9';ch++){
            if(root->children.find(ch)!=root->children.end())
                dfs(root->children[ch],(current*10 )+ (ch - '0'));
        }
        return;
    }
};