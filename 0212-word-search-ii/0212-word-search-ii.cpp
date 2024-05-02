class Trie {
    public:
    unordered_map<char,Trie*> children;
    bool endOfWord;

    Trie(){
        this->endOfWord=false;
    }

    void addWord(string word){
        Trie* ptr=this;
        for(auto ch:word){
            if(ptr->children.find(ch)==ptr->children.end()){
                ptr->children[ch]=new Trie(); 
            }
            ptr=ptr->children[ch];
        }
        ptr->endOfWord=true;
    }
};

class Solution {
public:
    unordered_set<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for(auto word:words){
            root->addWord(word);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(i,j,"",board,root);
            }
        }
        vector<string> result(ans.begin(),ans.end());
        return result;
    }

    void dfs(int row,int col,string currWord,vector<vector<char>>& board,Trie* root){
        if(row<0 || col<0 || row>=board.size() || col>= board[0].size() || board[row][col]==' ' || root->children.find(board[row][col])==root->children.end())
            return;

        char ch=board[row][col];
        currWord+=ch;
        board[row][col]=' ';
        root=root->children[ch];
        if(root->endOfWord){
            ans.insert(currWord);
            return;
        }

        dfs(row+1,col,currWord,board,root);
        dfs(row-1,col,currWord,board,root);
        dfs(row,col+1,currWord,board,root);
        dfs(row,col-1,currWord,board,root);
        board[row][col]=ch;
        return;
    }
};

/*

words
ape
ace
app

a   c
p   e



*/