class TrieNode{
    public:
        vector<TrieNode*> children;
        bool end;
        TrieNode(){
            children.resize(10,NULL);
            end=false;
        }
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
                if(!current->children[ch-48])
                    current->children[ch-48]=new TrieNode();
                current=current->children[ch-48];
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
            if(root->children[ch-48])
                dfs(root->children[ch-48],(current*10 )+ (ch - '0'));
        }
        return;
    }
};

// class Solution {
// public:
//     vector<int> ans;
//     vector<int> lexicalOrder(int n) {
//         int digits = min(n,9);
//         for(int i=1;i<=digits;i++){
//             solve(i,n);
//         }
//         return ans;
//     }

//     void solve(int num,int n){
//         if(num>n){
//             return;
//         }

//         ans.push_back(num);
//         for(int i=0;i<=9;i++){
//             solve(num*10+i,n);
//         }
//         return;
//     }
// };