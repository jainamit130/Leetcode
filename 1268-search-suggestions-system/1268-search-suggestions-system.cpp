class TrieNode{
public:
    TrieNode *links[26];
    bool isEnd;
    TrieNode(){
        memset(links,0,sizeof(links));
        isEnd=false;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string &word) {
        TrieNode *node=root;
        for(char ch:word){
            if(!node->links[ch-'a']){
                node->links[ch-'a']=new TrieNode();
            }
            node=node->links[ch-'a'];
        }
        node->isEnd=true;
    }
    
    vector<string> search(string &word) {
        TrieNode* node =root;
        vector<string> prod;
        for(char ch:word){
            if(node->links[ch-'a'])
                node=node->links[ch-'a'];
            else return prod;
        }
        dfs(node,word,prod);
        return prod;
    }
    void dfs(TrieNode* node,string &s,vector<string> &prod){
        if(prod.size()==3) return;
        if(node->isEnd){
            prod.push_back(s);
        }
        for(char i='a';i<='z';i++){
            if(prod.size()==3) return;
            if(node->links[i-'a']){
                s+=i;
                dfs(node->links[i-'a'],s,prod);
                s=s.substr(0,s.size()-1);
            } 
        }
    }
    
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string search) {
        Trie trie=Trie();
        for(string &word:products){
            trie.insert(word);
        }
        vector<vector<string>> ans;
        string pre="";
        for(char &ch:search){
            pre+=ch;
            ans.push_back(trie.search(pre));
        }
        return ans;
    }
};

// class TrieNode {
//     public: 
//         vector<TrieNode*> children;
//         bool end;
//         TrieNode(){
//             children.resize(26,NULL);
//             end=false;
//         }
// };

// class Solution {
// public:
//     vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
//         TrieNode* root=new TrieNode();
        
//         //Create Trie
//         for(string word:products){
//             TrieNode* ptr=root;
//             for(char letter:word){
//                 if(ptr->children[letter-'a']==NULL){
//                     ptr->children[letter-'a']=new TrieNode();
//                 }
//                 ptr=ptr->children[letter-'a'];
//             }
//             ptr->end=true;
//         }

//         //Search Word
//         vector<vector<string>> ans;
//         string currentSearchWord="";
//         for(char letter:searchWord){
//             vector<string> resultWords;
//             currentSearchWord+=letter;
//             int size=2;
//             if(root->children[letter-'a']!=NULL){
//                 findAtmost3Words(root->children[letter-'a'],size,resultWords,currentSearchWord);
//             } 
//             for(auto s:resultWords){
//                 cout<<currentSearchWord<<"->"<<s<<endl;
//             }
//             ans.push_back(resultWords);
//         }
//         return ans;
//     }

//     vector<string> search(string &word) {
//         TrieNode* node =root;
//         vector<string> prod;
//         for(char ch:word){
//             if(node->links[ch-'a'])
//                 node=node->links[ch-'a'];
//             else return prod;
//         }
//         findAtmost3Words(node,word,prod);
//         return prod;
//     }

//     void findAtmost3Words(TrieNode* root,vector<string>& resultWords,string currentSearchWord){
//         if(root->end){
//             resultWords.push_back(currentSearchWord);
//             return;
//          }

//         if(resultWords.size()==3)
//             return;

//          for(char ch='a';ch<='z';ch++){
//             if(root->children[ch-'a']!=NULL){
//                 findAtmost3Words(root->children[ch-'a'],resultWords,currentSearchWord+ch);
//             }
//          }
//          return;
//     }
// };









/*


                        m
                        o
                    b   n   u
                    e   s   i



*/